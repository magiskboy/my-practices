use crate::state::TodoStatus;
use serde::Deserialize;
use validator::Validate;

#[derive(Deserialize, Validate)]
pub struct CreateTodoDto {
    #[validate(length(
        min = 3,
        max = 100,
        message = "Name's length must be between 3 - 10 characters"
    ))]
    pub name: String,

    #[validate(length(
        min = 20,
        max = 500,
        message = "Description's length must be between 20 - 500 characters"
    ))]
    pub description: Option<String>,
}

#[derive(Deserialize, Validate)]
#[serde(rename_all = "camelCase")]
pub struct UpdateTodoDto {
    #[validate(length(
        min = 3,
        max = 100,
        message = "Name's length must be between 3 - 10 characters"
    ))]
    pub name: Option<String>,

    #[validate(length(
        min = 20,
        max = 500,
        message = "Description's length must be between 20 - 500 characters"
    ))]
    pub description: Option<String>,

    pub status: Option<TodoStatus>,
}
