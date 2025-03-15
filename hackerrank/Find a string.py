def count_substring(string, sub_string):
    s = len(sub_string)
    c = 0
    for i in range(len(string)-s+1):
        if string[i:i+s] == sub_string:
            c += 1
    return c