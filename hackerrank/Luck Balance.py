#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the luckBalance function below.
def luckBalance(k, contests):
    c = 0
    v = []
    for i in range(len(contests)):
        if contests[i][1] == 0:
            c += contests[i][0]
        else:
            v.append(contests[i][0])
    v = sorted(v, reverse=True)
    c += sum(v[:k])
    return c - sum(v[k:])


if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    nk = input().split()

    n = int(nk[0])

    k = int(nk[1])

    contests = []

    for _ in range(n):
        contests.append(list(map(int, input().rstrip().split())))

    result = luckBalance(k, contests)

    fptr.write(str(result) + '\n')

    fptr.close()
