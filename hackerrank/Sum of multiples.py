from functools import lru_cache


def sum(n):
    k1, k2, k3 = n // 3, n // 5, n // 15
    s1 = 3 * (k1 * (k1 + 1) / 2)
    s2 = 5 * (k2 * (k2 + 1) / 2)
    s3 = 15 * (k3 * (k3 + 1) / 2)
    return int(s1 + s2 - s3)

if __name__ == "__main__":
    rv = []
    t = int(input())
    for _ in range(t):
        n = int(input())
        rv.append(sum(n-1))
    for _ in rv:
        print(_)
