#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the surfaceArea function below.
def surfaceArea(A):
    m = len(A)
    n = len(A[0])
    a = []
    for row in A:
        row = [0] + row + [0]
        a.append(row)
    A = ([[0 for _ in range(n+2)]]) + a + ([[0 for _ in range(n+2)]])
    ret = 0
    for i in range(1, m+1):
        for j in range(1, n+1):
            ret += max(A[i][j]-A[i-1][j], 0)
            ret += max(A[i][j]-A[i+1][j], 0)
            ret += max(A[i][j]-A[i][j-1], 0)
            ret += max(A[i][j]-A[i][j+1], 0)
            ret += 2
    return ret

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    HW = input().split()

    H = int(HW[0])

    W = int(HW[1])

    A = []

    for _ in range(H):
        A.append(list(map(int, input().rstrip().split())))

    result = surfaceArea(A)

    fptr.write(str(result) + '\n')

    fptr.close()
