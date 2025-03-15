n = int(input())
s = 0

if n == 1:
    print(1)
else:
    for _ in range(n-1):
        v = int(input())
        s += v

    sa = int(n * (n+1)/2)
    print(sa - s)
