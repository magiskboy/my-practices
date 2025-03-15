n = input()
a = list(map(int, input().split(" ")))
a = sorted(a)
if len(a) == 1:
    print(a[0])
else:
    if len(a) == 2:
        print(a[0] * a[1])
    else:
        s1 = a[0] * a[1]
        s2 = a[-1] * a[-2]
        if s1 > s2:
            print(s1)
        else:
            print(s2)

