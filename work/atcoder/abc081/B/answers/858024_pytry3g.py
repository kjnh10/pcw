N = int(input())
A = list(map(int, input().split()))
ans = 0
flag = False
while True:
    for i in range(N):
        if A[i] % 2 != 0:
            flag = True
            break
        A[i] = A[i] // 2
    else:
        ans += 1
        if 0 in A:
            break
    if flag:
        break
print(ans)
