#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the candies function below.
def candies(n, arr):
    l = [0] * n
    l[0] = 1
    for i in range(1,n):
        if arr[i] > arr[i-1]:
            l[i] = l[i-1]+1
        else:
            l[i] = 1
    r = [0] * n
    r[n-1] = 1
    for i in range(n-2,-1,-1):
        if arr[i] > arr[i+1]:
            r[i] = r[i+1] + 1
        else:
            r[i] = 1
    return sum(map(lambda x: max(*x), zip(l,r)))

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input())

    arr = []

    for _ in range(n):
        arr_item = int(input())
        arr.append(arr_item)

    result = candies(n, arr)

    fptr.write(str(result) + '\n')

    fptr.close()
