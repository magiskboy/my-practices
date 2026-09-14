use tokio;

use crate::config::Config;
use crate::routes::{create_todo, delete_todo, get_todos, update_todo};
use crate::state::AppState;
use axum::Router;
use axum::routing::{delete, get, post, put};
use sqlx;
use sqlx::mysql::MySqlPoolOptions;

mod config;
mod dto;
mod error;
mod routes;
mod state;

#[tokio::main]
async fn main() {
    let config = Config::new();

    println!("Configuration:\n{}", config);

    let db = MySqlPoolOptions::new()
        .max_connections(config.db_max_connections)
        .connect(&config.db_uri)
        .await
        .unwrap();

    let state = AppState { db: db };

    let app = Router::new()
        .route("/todos", post(create_todo))
        .route("/todos", get(get_todos))
        .route("/todos/{id}", put(update_todo))
        .route("/todos/{id}", delete(delete_todo))
        .route("/health", get(async || "ok"))
        .with_state(state);

    let listener = tokio::net::TcpListener::bind(&config.binding_address)
        .await
        .unwrap();

    println!("Server is starting on {}", config.binding_address);
    axum::serve(listener, app).await.unwrap();
}
