def is_even(p):
    c = 0
    for i in range(len(p)-1):
        for j in range(i+1, len(p)):
            if p[i] > p[j]:
                c += 1
                p[i], p[j] = p[j], p[i]
    return c % 2 == 0


if __name__ == '__main__':
    p = [0, 3, 2, 4, 5, 6, 7, 1, 9, 8]
    print(is_even(p))
