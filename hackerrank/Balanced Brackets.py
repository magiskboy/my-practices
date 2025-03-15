#!/bin/python3

import os
from collections import deque

pairs = {'}': '{', ')': '(', ']': '['}

# Complete the isBalanced function below.
def isBalanced(s):
    stack = deque()
    for c in s:
        if c in ['{', '[', '(']:
            stack.appendleft(c)
        else:
            if len(stack) == 0:
                return "NO"
            else:
                if pairs[c] != stack[0]:
                    return "NO"
                else:
                    stack.popleft()
    if len(stack) > 0:
        return "NO"
    else:
        return 'YES'

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    t = int(input())

    for t_itr in range(t):
        s = input()

        result = isBalanced(s)

        fptr.write(result + '\n')

    fptr.close()
