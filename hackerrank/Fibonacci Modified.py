arr = map(int, raw_input().split())

c = 0
for i in range(arr[2]-2):
    c = arr[0] + arr[1] * arr[1]
    arr[0] = arr[1]
    arr[1] = c

print(str(arr[1]))