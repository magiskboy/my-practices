import random


_CHARS = "abcdefghjklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"


def gen_code(url, length=6):
    global _CHARS
    seed = 1
    for c in url:
        seed = random.randint(0, 2**ord(c))
        random.seed(seed)
    code = [_CHARS[random.randint(0, len(_CHARS))] for _ in range(length)]
    return "".join(code)


def build_url(base, port, code):
    return "http://" + base + ":" + str(port) + "/_" + "/" + code
