import math
t = int(input())
while t > 0:
    n, k = [int(x) for x in input().split()]
    a = []
    while len(a) < n:
        b = [int(x) for x in input().split()]
        for z in b:
            a.append(z)
    t -= 1
    res = n + 1
    for i in range(n):
        x = a[i]
        for j in range(i, n):
            if (math.gcd(x, a[j]) == k):
                res = min(res, j - i + 1)
                break
            else:
                x = math.gcd(x, a[j])
    if (res == n + 1):
        print(-1)
    else:
        print(res)