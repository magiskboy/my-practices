import random
import time

def prime_async(n):
    if n < 4:
        yield True
        return
    for i in range(2, int(n**0.5)+1):
        if n % i == 0:
            yield False
            return
        else:
            yield
    yield True
    return

def prime_sync(n):
    if n < 4:
        yield True
        return
    c = True
    for i in range(2, int(n**0.5)+1):
        if n % i == 0:
            c = False
            break
    yield c
    return

class Task(object):
    def __init__(self, func, args):
        self.id = id(self)
        self.coroutine = func(*args)
        self.args = args
        self.done = False
        self.result = None

    def __next__(self):
        try:
            self.result = next(self.coroutine)
        except StopIteration:
            self.done = True
            #print('ID: {} - Result: {} - Param: {}'.format(self.id, self.result, self.args))
        else:
            pass

class Executor(object):
    def __init__(self, tasks):
        self.tasks = tasks

    def run(self):
        start = time.time()
        while True:
            working_task = list(filter(lambda task: not task.done, self.tasks))
            if not working_task:
                break
            for task in working_task:
                next(task)
        print('Time: {}'.format(time.time()-start))

if __name__ == '__main__':
    n = 1000
    rang = 1000000000

    print('Async')
    tasks = [Task(prime_async, args=(random.randint(2, rang),)) for _ in range(n)]
    executor = Executor(tasks)
    executor.run()

    print('Sync')
    tasks = [Task(prime_sync, args=(random.randint(2, rang),)) for _ in range(n)]
    executor = Executor(tasks)
    executor.run()
