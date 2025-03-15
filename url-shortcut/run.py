import tornado.ioloop
from app import create_app


if __name__ == "__main__":
    application = create_app()
    application.listen(8888)
    print("Server running at localhost on port 8888...")
    tornado.ioloop.IOLoop.current().start()
