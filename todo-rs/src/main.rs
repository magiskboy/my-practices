use tokio;

mod routes;
mod state;


#[tokio::main]
async fn main() {
    let app = routes::make_app().await;
    let listener = tokio::net::TcpListener::bind("127.0.0.1:3000").await.unwrap();
    println!("Server is starting on 127.0.0.1:3000");
    axum::serve(listener, app).await.unwrap();
}
