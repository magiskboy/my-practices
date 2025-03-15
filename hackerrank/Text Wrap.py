def wrap(string, max_width):
    r = textwrap.wrap(string, max_width)
    re = ''
    for i in r:
        re += i + '\n'
    return re