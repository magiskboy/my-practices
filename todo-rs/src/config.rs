use std::{env::var, fmt::Display};

pub struct Config {
    pub db_uri: String,
    pub db_max_connections: u32,
    pub binding_address: String,
}

impl Display for Config {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        let _ = writeln!(f, "db_uri: {}", self.db_uri);
        let _ = writeln!(f, "db_max_connections: {}", self.db_max_connections);
        let _ = writeln!(f, "binding_address: {}", self.binding_address);

        Ok(())
    }
}

impl Config {
    pub fn new() -> Self {
        let db_uri = var("APP_DB_URI")
            .unwrap_or_else(|_| "mysql://todo_rs:todo_rs@127.0.0.1:3306/todo_rs".to_string());
        let binding_address =
            var("APP_BINDING_ADDR").unwrap_or_else(|_| "127.0.0.1:3000".to_string());

        let db_max_connections_str =
            var("APP_DB_MAX_CONNECTIONS").unwrap_or_else(|_| "5".to_string());
        let mut db_max_connections: u32 = 5;
        if let Ok(v) = db_max_connections_str.parse::<u32>() {
            db_max_connections = v;
        }

        Config {
            db_uri,
            db_max_connections,
            binding_address,
        }
    }
}
