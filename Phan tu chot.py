def process():
    n = int(input())
    a = [int(i) for i in input().split()]
    mi = []
    for i in range(n - 1):
        mi.append(0)
    mi.append(a[-1])
    mx = [a[0]]
    for i in range(1, n):
        if mx[i-1] < a[i]:
            mx.append(a[i])
        else:
            mx.append(mx[i-1])
    for i in range(n - 2, -1, -1):
        if mi[i+1] > a[i]:
            mi[i] = a[i]
        else:
            mi[i] = mi[i+1]
    ans = 0
    if a[0] < mi[1]:
        ans += 1
    if a[-1] >= mx[-2]:
        ans += 1
    for i in range(1, n - 1):
        if a[i] >= mx[i-1] and a[i] < mi[i+1]:
            ans += 1
    print(ans)

t = int(input())
while t > 0:
	process()
	t -= 1