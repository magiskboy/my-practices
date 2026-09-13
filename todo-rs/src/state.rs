use uuid;
use std::sync::Arc;
use chrono::{DateTime, Utc};
use serde::{Serialize, Deserialize};
use tokio::sync::Mutex;
use sqlx::{mysql::MySqlPool, FromRow, Type};

#[derive(Deserialize, Serialize, Debug, Clone, Type, PartialEq)]
#[sqlx(type_name = "varchar", rename_all = "lowercase")]
pub enum TodoStatus {
    New,
    Progress,
    Done,
}

#[derive(Serialize, Deserialize, Debug, Clone, FromRow)]
#[serde(rename_all = "camelCase")]
pub struct Todo {
    pub id: uuid::Uuid,
    pub name: String,
    pub description: String,
    pub status: TodoStatus,
    pub created_at: DateTime<Utc>,
}

impl Todo {
    pub fn new() -> Self {
        Todo {
            id: uuid::Uuid::new_v4(),
            name: "".to_string(),
            description: "".to_string(),
            status: TodoStatus::New,
            created_at: chrono::Utc::now(),
        }
    }
}

#[derive(Clone)]
pub struct AppState {
    pub todos: Arc<Mutex<Vec<Todo>>>,
    pub db: MySqlPool,
}
