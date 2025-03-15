n = int(input())
m = {}

for _ in range(n):
    v = int(input())
    if v in m:
        m[v] += 1
    else:
        m[v] = 1

i = -1
for k, v in m.items():
    if v > n // 2:
        i = k

print(i)
