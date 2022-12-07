def distintBitwiseOR(arr, n):
    ans, prev = set(), set()
    for i in range(n):
        tmp = set()
        for x in prev:
            tmp.add(arr[i] | x)
        tmp.add(arr[i])
        for x in tmp:
            ans.add(x)
        prev = tmp
    return len(ans)

n = int(input())
arr = list(map(int, input().split()))
print(distintBitwiseOR(arr, n))