import re
import json
import tornado.web
from . import utils
from . import settings
from . import database


class MainHandler(tornado.web.RequestHandler):
    async def get(self):
        self.render("index.html")


class MakeShortcut(tornado.web.RequestHandler):
    async def post(self):
        body = {}
        if self.request.headers["Content-Type"] == "application/json":
            try:
                body = json.loads(self.request.body)
                if "url" not in body:
                    raise ValueError("url required")
                url = body["url"]
                if not (url.startswith("http://") or url.endswith("https://")):
                    url = "http://" + url
            except JSONDecodeError:
                self.write({"message": "Bad request"})
                self.set_status(400)
                self.finish()
            else:
                code = utils.gen_code(url, length=settings.CODE_LENGTH)
                database.create_url(code, url)
                payload = {
                    "short_url": utils.build_url(settings.DOMAIN_NAME,
                                           settings.PORT, code),
                    "code": 0
                }
                self.write(payload)
                self.set_header("Content-Type", "application/json")
                self.set_status(201)
                self.finish()
                

class ShortcutUrl(tornado.web.RequestHandler):
    def get(self, code):
        try:
            url = database.get_url(code)
            if url is None:
                raise ValueError("URL not found")
        except Exception as err:
            self.write(str(err))
            self.set_status(400)
            self.finish()
        else:
            self.redirect(url)
