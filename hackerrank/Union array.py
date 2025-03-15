t = int(input())
rv = []
for _ in range(t):
    n = input()
    a = list(map(int, input().split(" ")))
    b = list(map(int, input().split(" ")))
    c = list(set(a + b))
    rv.append(sorted(c))

for _ in rv:
    for x in _:
        print(str(x), end=" ")
    print("")

