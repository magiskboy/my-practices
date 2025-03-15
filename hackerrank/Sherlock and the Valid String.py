#!/bin/python3

import os
from collections import Counter

# Complete the isValid function below.
def isValid(s):
    d = list(Counter(s).values())
    if (sum(d) - len(d) * min(d) == 1) or (sum(d) / len(d) == d[0]) or (1 in d and (sum(d)-1) / (len(d)-1) == max(d)):
        return "YES"
    else:
        return "NO"

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    s = input()

    result = isValid(s)

    fptr.write(result + '\n')

    fptr.close()
