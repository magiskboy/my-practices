#!/bin/python3

import os
from collections import Counter

# Complete the beautifulPairs function below.
def beautifulPairs(A, B):
    rv = 0
    da = Counter(A)
    db = Counter(B)
    for k, v in da.items():
        if k in db:
            rv += v * db[k]
    return rv

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input())

    A = list(map(int, input().rstrip().split()))

    B = list(map(int, input().rstrip().split()))

    result = beautifulPairs(A, B)

    fptr.write(str(result) + '\n')

    fptr.close()
