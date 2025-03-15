#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the hackerlandRadioTransmitters function below.
def hackerlandRadioTransmitters(x, k):
    x.sort()
    c = 1
    head = x[0]
    prev = x[0]
    for xx in x[1:]:
        d = xx - head
        if d > k:
            head = xx
            prev = xx
            c += 1
        else:
            if xx - prev <= k:
                head = xx

    return c

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    nk = input().split()

    n = int(nk[0])

    k = int(nk[1])

    x = list(map(int, input().rstrip().split()))

    result = hackerlandRadioTransmitters(x, k)

    fptr.write(str(result) + '\n')

    fptr.close()
