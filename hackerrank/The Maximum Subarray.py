#!/bin/python3

import math
import os
import random
import re
import sys

def check_negative(arr):
    for _ in arr:
        if _ >= 0:
            return False
    return len(arr) != 1

def find_max_crossing_subarray(a, low, mid, high):
    left_sum = -999999999999999
    s, max_left = 0, 0
    for i in range(mid, low-1, -1):
        s += a[i]
        if s > left_sum:
            left_sum = s
            max_left = i
    right_sum = -99999999999999
    s, max_right = 0, 0
    for i in range(mid+1, high+1):
        s += a[i]
        if s > right_sum:
            right_sum = s
            max_right = i
    return max_left, max_right, left_sum + right_sum

def find_maximum_subarray(a, low, high):
    if low == high:
        return low, high, a[low]
    else:
        mid = (low + high) // 2
        left_low, left_high, left_sum = find_maximum_subarray(a, low, mid)
        right_low, right_high, right_sum = find_maximum_subarray(a, mid+1, high)
        cross_low, cross_high, cross_sum = find_max_crossing_subarray(a, low, mid, high)

        if left_sum >= right_sum and left_sum >= cross_sum:
            return left_low, left_high, left_sum
        elif right_sum >= left_sum and right_sum >= cross_sum:
            return right_low, right_high, right_sum
        else:
            return cross_low, cross_high, cross_sum

def find_maximum_sequence(a, low, high):
    if low == high:
        return a[low]
    else:
        mid = (low + high) // 2
        s_left = find_maximum_sequence(a, low, mid)
        s_right = find_maximum_sequence(a, mid + 1, high)
        return max(s_left, s_right, s_left + s_right)

# Complete the maxSubarray function below.
def maxSubarray(arr):
    if check_negative(arr):
        return -1, -1
        
    l, h, max_subarray = find_maximum_subarray(arr, 0, len(arr)-1)
    max_subsequence = find_maximum_sequence(arr, 0, len(arr)-1)
    return max_subarray, max_subsequence

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    t = int(input())

    for t_itr in range(t):
        n = int(input())

        arr = list(map(int, input().rstrip().split()))

        result = maxSubarray(arr)

        fptr.write(' '.join(map(str, result)))
        fptr.write('\n')

    fptr.close()
