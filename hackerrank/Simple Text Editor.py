# Enter your code here. Read input from STDIN. Print output to STDOUT
from queue import LifoQueue

stack = LifoQueue()
q = int(input())
s = ''
screen = []

for _ in range(q):
    inps = input().split()
    if len(inps) == 1:
        if not stack.empty():
            s = stack.get()
        else:
            stack.put('')
            s = ''
    else:
        a, b = inps
        if a == '1':
            stack.put(s)
            s += b
        elif a == '2':
            stack.put(s)
            s = s[:-int(b)]
        else:
            screen.append(s[int(b)-1])
            
for row in screen:
    print(row)
