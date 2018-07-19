N = int(input())
A = list(map(int, input().split()))
A.append(-1)
ans = 0
L = 0
for R in range(N + 1):
    if A[R] <= A[R - 1]:
        Len = R - L
        ans += Len * (Len + 1) // 2
        L = R
print(ans)
