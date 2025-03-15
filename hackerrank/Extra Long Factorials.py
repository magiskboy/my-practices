def f( n ):
    s = 1
    for i in range(2, int(n)+1):
        s = s * i;
    return s;

n = int(raw_input())

print str(f(n))