n = int(input())
A = [[] * n for _ in range(2)]
for i in range(2):
    a = list(map(int, input().split()))
    A[i] = a

ans = 0
for i in range(n):
    s = sum(A[0][:i + 1]) + sum(A[1][i:])
    ans = max(ans, s)

print(ans)