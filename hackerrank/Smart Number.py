import math

def is_smart_number(num):
    val = int(math.sqrt(num))
    n = 0
    for i in range(1, num+1):
        if (num % val) == 0:
            n += 1
    if n % 2:
        return True
    return False

for _ in range(int(input())):
    num = int(input())
    ans = is_smart_number(num)
    if ans:
        print("YES")
    else:
        print("NO")



