#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the countInversions function below.
def countInversions(arr):
    rv, _ = count_sort(arr)
    return rv

def merge_sort(a, b):
    ci, c = 0, []
    while len(a) > 0 and len(b) > 0:
        if a[0] > b[0]:
            ci += len(a)
            c.append(b[0])
            b = b[1:]
        else:
            c.append(a[0])
            a = a[1:]
    if len(a) > 0:
        c += a
    elif len(b) > 0:
        c += b
    return ci, c


def count_sort(l):
    if len(l) == 1:
        return 0, l
    else:
        n = len(l)
        a, b = l[:n//2], l[n//2:]
        xi, x = count_sort(a)
        yi, y = count_sort(b)
        zi, z = merge_sort(x, y)
        return xi + yi + zi, z

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    t = int(input())

    for t_itr in range(t):
        n = int(input())

        arr = list(map(int, input().rstrip().split()))

        result = countInversions(arr)

        fptr.write(str(result) + '\n')

    fptr.close()
