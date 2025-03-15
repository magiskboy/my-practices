#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the solve function below.
def is_leap(year):
    if (year <= 1917 and year % 4 == 0) or (year >= 1919 and (year % 400 == 0 or (year % 4 == 0 and year % 100 != 0))):
        return True
    return False

def get_days(month, year):
    if month in [1, 3, 5, 7, 8, 10, 12]:
        return 31
    elif month in [4, 6, 9, 11]:
        return 30
    elif year == 1918:
        return 15
    else:
        if is_leap(year):
            return 29
        else:
            return 28

def solve(year):
    month = 1
    day = 256
    while True:
        d = get_days(month, year)
        if day < d:
            break
        day -= d
        month += 1
    month = str(month) if len(str(month)) == 2 else '0'+str(month)
    day = str(day) if len(str(day)) == 2 else '0'+str(day)
    return '%s.%s.%s' % (day, month, year)
if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    year = int(input())

    result = solve(year)

    fptr.write(result + '\n')

    fptr.close()
