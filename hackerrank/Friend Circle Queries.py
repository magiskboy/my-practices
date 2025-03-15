#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the maxCircle function below.
def maxCircle(queries):
    results = []
    groups = {}
    persons = {}

    for a, b in queries:
        leader_a = persons.get(a)
        leader_b = persons.get(b)
        
        if leader_a and leader_b:
            if groups[leader_a] > groups[leader_b]:
                persons[leader_b] = leader_a
                groups[leader_a] += groups[leader_b]
                del groups[leader_b]
            else:
                persons[leader_a] = leader_b
                groups[leader_b] += groups[leader_a]
                del groups[leader_a]
        elif leader_a is None and leader_b is None:
            if a < b:
                persons[a] = a
                persons[b] = a
                groups[a] = 2
            else:
                persons[b] = b
                persons[a] = b
                groups[b] = 2
        elif leader_a is None:
            groups[leader_b] += 1
            persons[a] = leader_b
        elif leader_b is None:
            groups[leader_a] += 1
            persons[b] = leader_a

        results.append(max(groups.values()))
        
    return results


if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    q = int(input())

    queries = []

    for _ in range(q):
        queries.append(list(map(int, input().rstrip().split())))

    ans = maxCircle(queries)

    fptr.write('\n'.join(map(str, ans)))
    fptr.write('\n')

    fptr.close()
