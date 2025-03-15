from . import handlers


urlpatterns = [
    (r"/", handlers.MainHandler),
    (r"/shortcut", handlers.MakeShortcut),
    (r"/_/?(?P<code>[A-Za-z0-9]+)?", handlers.ShortcutUrl)
]
