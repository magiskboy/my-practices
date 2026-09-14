use crate::dto::{CreateTodoDto, UpdateTodoDto};
use crate::error::AppError;
use crate::state::{AppState, Todo};
use axum::extract::Path;
use axum::{Json, extract::State};
use serde_json::{Value, json};
use sqlx;
use validator::Validate;

pub async fn get_todos(State(state): State<AppState>) -> Result<Json<Vec<Todo>>, AppError> {
    let todos = sqlx::query_as::<sqlx::MySql, Todo>(
        "SELECT id, name, description, status, created_at, is_deleted FROM tb_todos WHERE is_deleted = false"
    )
        .fetch_all(&state.db)
        .await
        .map_err(|err| AppError::UnexpectedError(err.to_string()))?;

    Ok(Json(todos))
}

pub async fn create_todo(
    State(state): State<AppState>,
    Json(payload): Json<CreateTodoDto>,
) -> Result<Json<Todo>, AppError> {
    if let Err(err) = payload.validate() {
        return Err(AppError::UnexpectedError(err.to_string()));
    }

    let mut todo = Todo::new();
    todo.name = payload.name;
    if let Some(description) = payload.description {
        todo.description = description;
    }

    let _ = sqlx::query::<sqlx::MySql>(
        r#"INSERT INTO tb_todos (id, name, description) VALUES (?, ?, ?)"#,
    )
    .bind(&todo.id)
    .bind(&todo.name)
    .bind(&todo.description)
    .execute(&state.db)
    .await
    .map_err(|err| AppError::UnexpectedError(err.to_string()));

    Ok(Json(todo))
}

pub async fn update_todo(
    State(state): State<AppState>,
    Path(id): Path<uuid::fmt::Hyphenated>,
    Json(payload): Json<UpdateTodoDto>,
) -> Result<Json<Todo>, AppError> {
    let mut todo = sqlx::query_as::<sqlx::MySql, Todo>(
        r#"SELECT id, name, description, status, created_at, is_deleted FROM tb_todos WHERE id = ? AND is_deleted = ?"#
    )
        .bind(&id)
        .bind(false)
        .fetch_optional(&state.db)
        .await
        .map_err(|err| AppError::UnexpectedError(err.to_string()))?
        .ok_or_else(|| AppError::TodoNotFound(id.clone()))?;

    if let Some(name) = payload.name {
        todo.name = name;
    }

    if let Some(description) = payload.description {
        todo.description = description;
    }

    if let Some(status) = payload.status {
        todo.status = status;
    }

    let _ = sqlx::query(
        r#"UPDATE tb_todos SET name = ?, description = ?, status = ? WHERE id = ? AND is_deleted = ?"#
    )
        .bind(&todo.name)
        .bind(&todo.description)
        .bind(&todo.status)
        .bind(&id)
        .bind(false)
        .execute(&state.db)
        .await
        .map_err(|err| AppError::UnexpectedError(err.to_string()));

    Ok(Json(todo))
}

pub async fn delete_todo(
    State(state): State<AppState>,
    Path(id): Path<uuid::fmt::Hyphenated>,
) -> Result<Json<Value>, AppError> {
    let _ = sqlx::query(r#"UPDATE tb_todos SET is_deleted = true WHERE id = ?"#)
        .bind(id)
        .execute(&state.db)
        .await
        .map_err(|err| AppError::UnexpectedError(err.to_string()));

    Ok(Json(json!({
        "message": format!("Todo {} was deleted", id).to_string(),
    })))
}
