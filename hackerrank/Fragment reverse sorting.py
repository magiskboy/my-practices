n = input()
a = list(map(int, input().split(" ")))
c = True
begin = -1
rv = "YES"

for i in range(len(a)-1):
    if a[i] > a[i+1]:
        if c:
            begin = i  
        else:
            rv = "NO"
            break
    else:
        if begin != -1:
            c = False

print(rv)
