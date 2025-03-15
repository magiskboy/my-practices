#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the minimumLoss function below.
def minimumLoss(price):
    m = 99999999999
    x = sorted(enumerate(price), key=lambda x: x[1])
    for i in range(len(x)-1):
        if x[i][0] > x[i+1][0]:
            m = min(x[i+1][1]-x[i][1], m)
    return m

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input())

    price = list(map(int, input().rstrip().split()))

    result = minimumLoss(price)

    fptr.write(str(result) + '\n')

    fptr.close()
