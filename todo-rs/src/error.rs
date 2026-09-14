use axum::http::StatusCode;
use axum::{Json, response::IntoResponse};
use serde::Serialize;

#[derive(Serialize)]
pub enum AppError {
    UnexpectedError(String),
    TodoNotFound(uuid::fmt::Hyphenated),
}

#[derive(Serialize)]
struct ErrorBody {
    pub message: String,
    pub code: &'static str,
}

impl IntoResponse for AppError {
    fn into_response(self) -> axum::response::Response {
        let (status, code, message) = match self {
            AppError::UnexpectedError(msg) => {
                (StatusCode::INTERNAL_SERVER_ERROR, "unexpected_error", msg)
            }
            AppError::TodoNotFound(id) => (
                StatusCode::NOT_FOUND,
                "todo_not_found",
                format!("Todo {} not found", id),
            ),
        };

        (status, Json(ErrorBody { message, code })).into_response()
    }
}
