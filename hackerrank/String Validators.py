if __name__ == '__main__':
    s = raw_input()
    c = [False, False, False, False, False]
    for x in s:
        if x.isalnum():
            c[0] = True
        if x.isalpha():
            c[1] = True
        if x.isdigit():
            c[2] = True
        if x.islower():
            c[3] = True
        if x.isupper():
            c[4] = True
        if all(c):
            break;
    for x in c:
        print x