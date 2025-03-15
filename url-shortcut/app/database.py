storage = {}


def get_url(code):
    global storage
    return storage.get(code)


def update_url(code, url):
    global storage
    if code in storage:
        storage[code] = url
    return code, url


def create_url(code, url):
    global storage
    if code in storage:
        return
    storage.update({code: url})
    return code, url


def delete_url(code):
    global storage
    if code in storage:
        del storage[code]


def check_code(code):
    global storage
    return code in storage
