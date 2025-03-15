#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the minimumSwaps function below.
def minimumSwaps(arr):
    cnt = 0
    m = {}
    for i in range(len(arr)):
        m[arr[i]] = i
    
    for i in range(len(arr)):     
        r = i + 1
        if r == arr[i]:
            continue
        
        j = m.get(r)
        arr[i], arr[j] = arr[j], arr[i]
        m[arr[i]], m[arr[j]] = i, j
        cnt += 1
        
    return cnt

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input())

    arr = list(map(int, input().rstrip().split()))

    res = minimumSwaps(arr)

    fptr.write(str(res) + '\n')

    fptr.close()
