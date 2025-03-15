def f( s, k ):
    if len(str(s)) * k == 1:
        return s
    else:
        sum = 0
        for x in str(s):
            sum += int(x)
        sum = sum * k
        return f(sum, 1)
    
a = map(int, raw_input().split())

print(str(f(a[0], a[1])))