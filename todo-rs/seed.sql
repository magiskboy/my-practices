USE todo_rs;

CREATE TABLE IF NOT EXISTS tb_todos (
    id VARCHAR(36) NOT NULL,
    name VARCHAR(100) NOT NULL,
    description VARCHAR(500) DEFAULT "",
    status VARCHAR(10) NOT NULL DEFAULT "new",
    created_at DATETIME DEFAULT now()
);

