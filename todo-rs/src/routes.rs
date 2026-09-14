use axum::extract::Path;
use axum::http::StatusCode;
use axum::{Router, Json, extract::State, response::IntoResponse};
use axum::routing::{get, post, put, delete};
use serde::{Deserialize, Serialize};
use sqlx::mysql::{MySqlPoolOptions};
use sqlx;
use crate::state::{AppState, Todo, TodoStatus};

#[derive(Serialize)]
enum AppError {
    UnexpectedError(String),
    TodoNotFound(uuid::fmt::Hyphenated),
}

#[derive(Serialize)]
struct ErrorBody {
    message: String,
    code: &'static str,
}

impl IntoResponse for AppError {
    fn into_response(self) -> axum::response::Response {
        let (status, code, message) = match self {
            AppError::UnexpectedError(msg) => (StatusCode::INTERNAL_SERVER_ERROR, "unexpected_error", msg),
            AppError::TodoNotFound(id) => (StatusCode::NOT_FOUND, "todo_not_found", format!("Todo {} not found", id)),
        };

        (status, Json(ErrorBody{message, code})).into_response()
    }
}


async fn get_todos(State(state): State<AppState>) -> Result<Json<Vec<Todo>>, AppError> {
    let todos = sqlx::query_as::<sqlx::MySql, Todo>(
        "SELECT id, name, description, status, created_at, is_deleted FROM tb_todos WHERE is_deleted = false"
    )
        .fetch_all(&state.db)
        .await
        .map_err(|err| AppError::UnexpectedError(err.to_string()))?;

    Ok(Json(todos))
}


#[derive(Deserialize)]
struct CreateTodoDto {
    name: String,
    description: String,
}

async fn create_todo(
    State(state): State<AppState>,
    Json(payload): Json<CreateTodoDto>
) -> Result<Json<Todo>, AppError> {
    let mut todo = Todo::new();
    todo.name = payload.name;
    todo.description = payload.description;
    let _ = sqlx::query::<sqlx::MySql>(
        r#"INSERT INTO tb_todos (id, name, description) VALUES (?, ?, ?)"#
    )
        .bind(&todo.id)
        .bind(&todo.name)
        .bind(&todo.description)
        .execute(&state.db)
        .await
        .map_err(|err| AppError::UnexpectedError(err.to_string()));

    Ok(Json(todo))
}

#[derive(Deserialize)]
#[serde(rename_all = "camelCase")]
struct UpdateTodoDto {
    name: String,
    description: String,
    status: TodoStatus,
    is_deleted: bool,
}

async fn update_todo(
    State(state): State<AppState>,
    Path(id): Path<uuid::fmt::Hyphenated>,
    Json(payload): Json<UpdateTodoDto>,
) -> Result<Json<Todo>, AppError> {
    let _ = sqlx::query(
        r#"UPDATE tb_todos SET name = ?, description = ?, status = ?, is_deleted = ? WHERE id = ? AND is_deleted = ?"#
    )
        .bind(&payload.name)
        .bind(&payload.description)
        .bind(&payload.status)
        .bind(&payload.is_deleted)
        .bind(&id)
        .bind(false)
        .execute(&state.db)
        .await
        .map_err(|err| AppError::UnexpectedError(err.to_string()));

    let todo = sqlx::query_as::<sqlx::MySql, Todo>(
        r#"SELECT id, name, description, status, created_at, is_deleted FROM tb_todos WHERE id = ? AND is_deleted = ?"#
    )
        .bind(&id)
        .bind(false)
        .fetch_optional(&state.db)
        .await
        .map_err(|err| AppError::UnexpectedError(err.to_string()))?
        .ok_or_else(|| AppError::TodoNotFound(id.clone()))?;

    Ok(Json(todo))
}


#[derive(Serialize)]
struct DeletedTodoResponse {
    message: String,
}

async fn delete_todo(
    State(state): State<AppState>,
    Path(id): Path<uuid::fmt::Hyphenated>,
) -> Result<Json<DeletedTodoResponse>, AppError>{
    let _ = sqlx::query(
        r#"UPDATE tb_todos SET is_deleted = true WHERE id = ?"#
    )
        .bind(id)
        .execute(&state.db)
        .await
        .map_err(|err| AppError::UnexpectedError(err.to_string()));

    Ok(Json(DeletedTodoResponse { message: format!("Todo {} was deleted", id).to_string() }))
}

pub async fn make_app() -> Router {
    let db_uri = "mysql://todo_rs:todo_rs@127.0.0.1:3306/todo_rs";
    let db = MySqlPoolOptions::new()
        .max_connections(5)
        .connect(db_uri).await.unwrap();

    let state = AppState {
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

