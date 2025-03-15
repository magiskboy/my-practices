# Enter your code here. Read input from STDIN. Print output to STDOUT
from queue import LifoQueue

stack = LifoQueue()
ret = []
n = int(input())

for _ in range(n):
    inps = input().split()
    
    if len(inps) > 1:
        new_v = int(inps[1])
        
        if stack.empty():
            stack.put((new_v, new_v))
        else:
            v, max_v = stack.get()
            new_max_v = max(max_v, new_v)
            stack.put((v, max_v))
            stack.put((new_v, new_max_v))
    elif inps[0] == '2':
        if not stack.empty():
            stack.get()
    else:
        if not stack.empty():
            v, max_v = stack.get()
            print(max_v)
            stack.put((v, max_v)) 
