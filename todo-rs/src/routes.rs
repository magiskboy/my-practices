use std::sync::Arc;

use axum::extract::Path;
use axum::http::StatusCode;
use axum::{Router, Json, extract::State, response::IntoResponse};
use axum::routing::{get, post, put, delete};
use serde::{Deserialize};
use tokio::sync::Mutex;
use sqlx::mysql::{MySqlPoolOptions};
use sqlx;

use crate::state::{AppState, Todo};


#[derive(Deserialize)]
struct CreateTodoDto {
    name: String,
    description: String,
}

async fn create_todo(
    State(state): State<AppState>,
    Json(payload): Json<CreateTodoDto>
) -> impl IntoResponse {
    let mut todo = Todo::new();
    todo.name = payload.name;
    todo.description = payload.description;
    let mut todos = state.todos.lock().await;
    let todo_id = todo.id.to_string();
    todos.push(todo);

    format!("Create a new todo successfully, ID = {}", todo_id)
}

#[derive(Deserialize)]
#[serde(rename_all = "camelCase")]
struct UpdateTodoDto {
    name: String,
    description: String,
}

async fn update_todo(
    State(state): State<AppState>,
    Path(id): Path<uuid::Uuid>,
    Json(payload): Json<UpdateTodoDto>,
) ->impl IntoResponse {
    let mut todos = state.todos.lock().await;
    let found = todos.iter_mut().find(|x| {
        x.id == id
    });

    match found {
        Some(item) => {
            item.name = payload.name;
            item.description = payload.description;
            (StatusCode::OK, format!("Updated todo {} successfully", item.id)).into_response()
        },
        None => (StatusCode::NOT_FOUND, format!("Todo {} not found", id)).into_response()
    }

}

async fn get_todos(
    State(state): State<AppState>,
) ->Json<Vec<Todo>> {
    let items = sqlx::query_as!(
        Todo, 
        r#"SELECT id, name, description, status, created_at FROM tb_todos"#
    )
    .fetch_all(state.db)
    .await;

    let todos = state.todos.lock().await;
    Json(todos.clone())
}


async fn delete_todo(
    State(state): State<AppState>,
    Path(id): Path<uuid::Uuid>,
) ->impl IntoResponse {
    let mut todos = state.todos.lock().await;
    let idx_op = todos.iter().position(|x| x.id == id);

    match idx_op {
        Some(deleted_idx) => {
            let deleted = todos.remove(deleted_idx);
            (StatusCode::OK, format!("Deleted {} successfully", deleted.id)).into_response()
        },
        None => {
            (StatusCode::NOT_FOUND, format!("Todo {} not found", id)).into_response()
        }
    }
}

pub async fn make_app() -> Router {
    let db_uri = "mysql://todo_rs:todo_rs@127.0.0.1:3306/todo_rs";
    let db = MySqlPoolOptions::new()
        .max_connections(5)
        .connect(db_uri).await.unwrap();

    let state = AppState {
        todos: Arc::new(Mutex::new(Vec::new())),
        db: db,
    };

    return Router::new()
        .route("/todos", post(create_todo))
        .route("/todos", get(get_todos))
        .route("/todos/{id}", put(update_todo))
        .route("/todos/{id}", delete(delete_todo))
        .route("/health", get(health))
        .with_state(state);
}

async fn health() -> &'static str  {
    "ok"
}

