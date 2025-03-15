#!/bin/python3

import os
from collections import Counter

def cond1(s):
    return len(list(set(s))) == 1

def cond2(s):
    if len(s) % 2 != 1: 
        return False
    c = s[len(s) // 2]
    d = Counter(s)
    return len(d.values()) == 2 and d[c] == 1

def cond(s):
    return cond1(s) or cond2(s)

# Complete the substrCount function below.
def substrCount(n, s):
    rv = 0
    for i in range(len(s)):
        for j in range(i+1, len(s)+1):
            if cond(s[i:j]):
                rv += 1
    return rv

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input())

    s = input()

    result = substrCount(n, s)

    fptr.write(str(result) + '\n')

    fptr.close()
