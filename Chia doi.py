import math
for t in range(int(input())):
	n = int(input())
	a = math.factorial(2*n)//(math.factorial(n+1)*math.factorial(n))
	print(a)