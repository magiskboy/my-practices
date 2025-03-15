def find_max_crossing_subarray(a, low, mid, high):
    left_sum = -999999999999999
    s, max_left = 0, 0
    for i in range(mid, low-1, -1):
        s += a[i]
        if s > left_sum:
            left_sum = s
            max_left = i
    right_sum = -99999999999999
    s, max_right = 0, 0
    for i in range(mid+1, high+1):
        s += a[i]
        if s > right_sum:
            right_sum = s
            max_right = i
    return max_left, max_right, left_sum + right_sum

def find_maximum_subarray(a, low, high):
    if low == high:
        return low, high, a[low]
    else:
        mid = (low + high) // 2
        left_low, left_high, left_sum = find_maximum_subarray(a, low, mid)
        right_low, right_high, right_sum = find_maximum_subarray(a, mid+1, high)
        cross_low, cross_high, cross_sum = find_max_crossing_subarray(a, low, mid, high)

        if left_sum >= right_sum and left_sum >= cross_sum:
            return left_low, left_high, left_sum
        elif right_sum >= left_sum and right_sum >= cross_sum:
            return right_low, right_high, right_sum
        else:
            return cross_low, cross_high, cross_sum

def find_maximum_sequence(a, low, high):
    if low == high:
        return a[low]
    else:
        mid = (low + high) // 2
        s_left = find_maximum_sequence(a, low, mid)
        s_right = find_maximum_sequence(a, mid + 1, high)
        return max(s_left, s_right, s_left + s_right)

if __name__ == '__main__':
    a = [2, -1, 2, 3, 4, -5]
    l, h, s = find_maximum_subarray(a, 0, len(a)-1)
    print(f"Sum({l},{h}) = {s}")
    print(f"Max sequence is {find_maximum_sequence(a, 0, len(a)-1)}")
