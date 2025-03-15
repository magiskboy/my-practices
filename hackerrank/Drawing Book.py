#!/bin/python

from __future__ import print_function

import os
import sys

#
# Complete the pageCount function below.
#
def pageCount(n, p):
    p1 = p/2
    p2 = (n-p)/2 if n % 2 != 0 else (n-p+1)/2
    return min(p1,p2)

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(raw_input())

    p = int(raw_input())

    result = pageCount(n, p)

    fptr.write(str(result) + '\n')

    fptr.close()
