_ = input()
a = list(map(int, input().split(" ")))

s = sum(a)
s1 = 0
for value in a:
    s1 += value
    if s1 > s - s1:
        t1 = abs(s - 2 * s1)
        s1 -= value
        t2 = abs(s - 2 * s1)
        if t1 < t2:
            print(t1)
        else:
            print(t2)
        break
    else:
        continue
