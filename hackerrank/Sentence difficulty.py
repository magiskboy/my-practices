p = ["a", "o", "u", "i", "e", "A", "O", "U", "I", "E"]

t = int(input())
rv = []

def check(word):
    count = 0
    count2 = 0
    for c in word:
        if c not in p:
            count += 1
            count2 += 1
        else:
            count = 0
        if count == 4:
            return True
    return len(word)-count2 < count2

def f(s):
    rv = 0
    sc = 0
    words = s.split(" ")
    lwords = 0

    for word in words:
        if word:
            lwords += 1
            sc += check(word)
    rv = 5 * sc + 3 * (lwords-sc)

    return rv

for _ in range(t):
    s = input()
    rv.append(f(s))

for _ in rv:
    print(_)
