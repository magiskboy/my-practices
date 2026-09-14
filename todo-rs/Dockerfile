FROM rust:1.98.1-trixie AS builder

WORKDIR /app

COPY ./Cargo.lock ./Cargo.toml /app
COPY ./src /app/src

RUN cargo update

RUN cargo build --release

FROM debian:trixie AS runner

WORKDIR /app

RUN groupadd --system --gid 10001 app \
    && useradd --system \
       --uid 10001 \
       --gid 10001 \
       --home-dir /nonexistent \
       --no-create-home \
       --shell /usr/sbin/nologin \
       app

COPY --from=builder --chown=app:app /app/target/release/todo-rs /app/app

ENV RUST_LOG=info

EXPOSE 3000

USER app:app

ENTRYPOINT ["/app/app"]
