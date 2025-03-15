l = []

N = int(raw_input())

cmd = [ raw_input() for x in range(N) ]

for x in cmd:
	arr = x.split()
	if arr[0] == "insert":
		l.insert(int(arr[1]), int(arr[2]))
	elif arr[0] == "print":
		print l
	elif arr[0] == "remove":
		l.remove(int(arr[1]))
	elif arr[0] == "pop":
		l.pop()
	elif arr[0] == "sort":
		l.sort()
	elif arr[0] == "reverse":
		l.reverse()
	elif arr[0] == "append":
		l.append(int(arr[1]))


