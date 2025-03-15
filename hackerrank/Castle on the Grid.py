#!/bin/python3

import os
from collections import deque

d = [[-1, 0], [1, 0], [0, -1], [0, 1]]
trace = []

# Complete the minimumMoves function below.
def minimumMoves(grid, startX, startY, goalX, goalY):
    global trace
    stack = deque()
    marks = []
    # initial trace and marks
    for i in range(len(grid)):
        r = list()
        r1 = list()
        for j in range(len(grid[0])):
            r.append(False)
            r1.append([])
        marks.append(r)
        trace.append(r1)

    # Run algorithm
    stack.appendleft([startX, startY])
    while len(stack) > 0:
        px, py = stack.popleft()
        if px == goalX and py == goalY:
            c = 0
            cx, cy = goalX, goalY
            while cx != startX and cy != startY:
                cx, cy = trace[cx][cy]
                c += 1
            return c
        marks[px][py] = True 
        for dx, dy in d:
            x, y = px + dx, py + dy
            if x < 0 or y < 0 or x == len(grid[0]) or y == len(grid) or grid[x][y] == 'X' or marks[x][y]:
                continue
            else:
                trace[x][y] = [px, py]
                stack.appendleft([x, y])

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input())

    grid = []

    for _ in range(n):
        grid_item = input()
        grid.append(grid_item)

    startXStartY = input().split()

    startX = int(startXStartY[0])

    startY = int(startXStartY[1])

    goalX = int(startXStartY[2])

    goalY = int(startXStartY[3])

    result = minimumMoves(grid, startX, startY, goalX, goalY)

    fptr.write(str(result) + '\n')

    fptr.close()
