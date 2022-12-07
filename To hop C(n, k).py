import math
for t in range(int(input())):
	n, k = map(int, input().split())
	a = math.factorial(n)//(math.factorial(n - k)*math.factorial(k)) % (1000000007)
	print(a)