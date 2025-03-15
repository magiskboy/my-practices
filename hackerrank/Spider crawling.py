x, y = tuple(map(int, input().split(" ")))
rv = 1

if x * y != 0:
    s = abs(x) + abs(y)
    for i in range(1, s):
        rv *= i

print(rv)
