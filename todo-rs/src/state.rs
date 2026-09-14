use chrono::{DateTime, Utc};
use serde::{Deserialize, Serialize};
use sqlx::encode::IsNull;
use sqlx::error::BoxDynError;
use sqlx::mysql::MySqlPool;
use sqlx::{Decode, Encode, FromRow, MySql, Type};

#[derive(Deserialize, Serialize, Debug, Clone, PartialEq)]
#[serde(rename_all = "lowercase")]
pub enum TodoStatus {
    New,
    Progress,
    Done,
}

impl TodoStatus {
    pub fn as_str(&self) -> &'static str {
        match self {
            TodoStatus::New => "new",
            TodoStatus::Progress => "progress",
            TodoStatus::Done => "done",
        }
    }

    pub fn from_str(s: &str) -> Result<Self, BoxDynError> {
        match s {
            "new" => Ok(TodoStatus::New),
            "progress" => Ok(TodoStatus::Progress),
            "done" => Ok(TodoStatus::Done),
            other => Err(format!("invalid TodoStatus: {other}").into()),
        }
    }
}

// Map enum <-> VARCHAR string for MySQL (avoid broken ENUM Type derive).
impl Type<MySql> for TodoStatus {
    fn type_info() -> sqlx::mysql::MySqlTypeInfo {
        <str as Type<MySql>>::type_info()
    }

    fn compatible(ty: &sqlx::mysql::MySqlTypeInfo) -> bool {
        <str as Type<MySql>>::compatible(ty)
    }
}

impl<'r> Decode<'r, MySql> for TodoStatus {
    fn decode(value: <MySql as sqlx::Database>::ValueRef<'r>) -> Result<Self, BoxDynError> {
        let s = <&str as Decode<'r, MySql>>::decode(value)?;
        Self::from_str(s)
    }
}

impl Encode<'_, MySql> for TodoStatus {
    fn encode_by_ref(
        &self,
        buf: &mut <MySql as sqlx::Database>::ArgumentBuffer,
    ) -> Result<IsNull, BoxDynError> {
        <&str as Encode<MySql>>::encode(self.as_str(), buf)
    }
}

#[derive(Serialize, Deserialize, Debug, Clone, FromRow)]
#[serde(rename_all = "camelCase")]
pub struct Todo {
    pub id: uuid::fmt::Hyphenated,
    pub name: String,
    pub description: String,
    pub status: TodoStatus,
    pub is_deleted: bool,
    pub created_at: DateTime<Utc>,
}

impl Todo {
    pub fn new() -> Self {
        let id = uuid::Uuid::new_v4();
        Todo {
            id: uuid::fmt::Hyphenated::from_uuid(id),
            name: "".to_string(),
            description: "".to_string(),
            is_deleted: false,
            status: TodoStatus::New,
            created_at: chrono::Utc::now(),
        }
    }
}

#[derive(Clone)]
pub struct AppState {
    pub db: MySqlPool,
}
