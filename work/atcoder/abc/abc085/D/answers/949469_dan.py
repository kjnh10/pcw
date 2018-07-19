N, H = map(int, input().split())
A = []
for _ in range(N):
    a, b = map(int, input().split())
    A.append((a, b))

A = sorted(A, key=lambda x: -x[0])
a = A[0][0]
ans = 0

A = sorted(A, key=lambda x: -x[1])
for i in range(N):
    if H <= 0:
        break
    if A[i][1] > a:
        ans += 1
        H -= A[i][1]

if H > 0:
    ans += (H + a - 1) // a

print(ans)
