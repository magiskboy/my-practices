if __name__ == '__main__':
    n = int(raw_input())
    arr = map(int, raw_input().split())
    
    arr.sort()
    
    arr.reverse()
    
    i = 0
    
    while arr[i] == arr[i+1]:
        i += 1
        
    print arr[i+1]
    
