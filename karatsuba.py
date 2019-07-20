def karatsuba(a, b):
    if len(a) == 1 or len(b) == 1:
        return int(a) * int(b)

    e = min(len(a), len(b)) - 1
    m, n = a[:len(a)-e], b[:len(b)-e]
    p, q = a[len(a)-e:], b[len(b)-e:]

    z1 = str(int(m) * int(n))
    z3 = karatsuba(p, q)
    z2 = karatsuba(str(int(m) + int(p)), str(int(n) + int(q)))
    z2 = str(int(z2) - int(z1) - int(z3))

    rv = str(10**(2*e) * int(z1) + 10**e * int(z2) + int(z3))
    return rv


if __name__ == "__main__":
    a = "3141592653589793238462643383279502884197169399375105820974944592"
    b = "2718281828459045235360287471352662497757247093699959574966967627"
    r = karatsuba(a, b)
    print("Result", r)
