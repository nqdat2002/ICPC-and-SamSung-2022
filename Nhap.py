f = []
def init():
    f.clear()
    for i in range(20):
        f.append([])
        for j in range(20):
            f[i].append([])
            for k in range(8):
                f[i][j].append([])
                for l in range(2):
                    f[i][j][k].append([])
                    for m in range(20):
                        f[i][j][k][l].append(-1)
                        
def calc(len, id, d, islower, cnt, a):
    if id == len + 1:
        if d == 0:
            return cnt
        return 0;
    x = f[len][id][d][islower][cnt]
    if x != -1:
        return x
    res = 0
    for i in range (10):
        if islower == 0 and i > a[id]:
            break
        new_islower = islower | (i < a[id])
        new_d = (d * 10 + i) % 8
        new_cnt = cnt + (i == 6 or i == 8)
        res += calc(len, id + 1, new_d, new_islower, new_cnt, a)
    f[len][id][d][islower][cnt] = res
    return res

t = int(input())
while t > 0:
    t -= 1
    init()
    n = int(input())
    s = str(n)
    a = [0] * (len(s) + 1)
    for i in range(1, len(s) + 1):
        a[i] = ord(s[i - 1]) - 48
    res = calc(len(s), 1, 0, 0, 0, a)
    print(res)      

