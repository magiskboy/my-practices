def sequence(arr, low, high):
    if high - low == 1:
        return arr[low]
    else:
        # divide
        mid = (high + low) // 2

        # conquer
        m1 = sequence(arr, low, mid)
        m2 = sequence(arr, mid, high)

        # combine
        if m1 > 0 and m2 > 0:
            return m1 + m2
        else:
            return max(m1, m2)


if __name__ == '__main__':
    a = [2, -1, 2, 3, 4, -5]
    m = sequence(a, 0, len(a))
    print(f'Max is {m}')
