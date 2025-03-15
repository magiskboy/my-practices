import os
import tornado.ioloop
import tornado.web
from . import urls


base = os.path.abspath(os.path.dirname(__file__))
template_path = os.path.join(base, "templates")


def create_app():
    """Function factory
    """
    global template_path
    application = tornado.web.Application(
        urls.urlpatterns,
        template_path=template_path
    )
    return application
