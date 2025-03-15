import math

def isPrime(n):
    if n < 2:
        return False
    elif n == 2 or n == 3:
        return True
    else:
        for i in range(2, int(math.sqrt(n))+1):
            if n % i == 0:
                return False
        return True

a = list()

for i in range( int(raw_input()) ):
	if isPrime(int(raw_input())):
		a.append("Prime")
	else:
		a.append("Not prime")

for x in a:
	print x

