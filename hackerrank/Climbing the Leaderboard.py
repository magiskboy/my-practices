#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the climbingLeaderboard function below.
def climbingLeaderboard(scores, alice):
    n = len(scores)
    m = len(alice)
    rank = 1
    ranks = [1]
    for i in range(1,n):
        if scores[i] < scores[i-1]:
            rank += 1
        ranks.append(rank)
    ret = []
    i = n
    for s in alice:
        while i >= 0 and s >= scores[i-1]:
            i -= 1
        if i == n:
            ret.append(ranks[-1]+1)
        elif i == -1:
            ret.append(1)
        else:
            ret.append(ranks[i])
    return ret


if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    scores_count = int(input())

    scores = list(map(int, input().rstrip().split()))

    alice_count = int(input())

    alice = list(map(int, input().rstrip().split()))

    result = climbingLeaderboard(scores, alice)

    fptr.write('\n'.join(map(str, result)))
    fptr.write('\n')

    fptr.close()
