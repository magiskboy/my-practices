from demo_pkg.mod1 import base_func

def display():
    print('demo_pkg/mod2.display')

def extend_func():
    base_func()
    print('extend func')
