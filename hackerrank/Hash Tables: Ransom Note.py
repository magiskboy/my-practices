#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the checkMagazine function below.
def checkMagazine(magazine, note):
    dmagazine, dnote = {}, {}
    for word in magazine:
        if word in dmagazine:
            dmagazine[word] += 1
        else:
            dmagazine[word] = 0
    for word in note:
        if word not in dmagazine:
            print("No")
            exit()
        else:
            if word not in dnote:
                dnote[word] = 0
            else:
                dnote[word] += 1
                if dnote[word] > dmagazine[word]:
                    print("No")
                    exit()
    print("Yes")
 
if __name__ == '__main__':
    mn = input().split()

    m = int(mn[0])

    n = int(mn[1])

    magazine = input().rstrip().split()

    note = input().rstrip().split()

    checkMagazine(magazine, note)
