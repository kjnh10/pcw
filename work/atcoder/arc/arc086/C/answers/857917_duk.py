N, K = map(int, input().split())
A = map(int, input().split())
B = [0] * (N + 1)
for a in A:
    B[a] += 1

B.sort()
B.reverse()

ans = 0
for i in range(K, N):
    ans += B[i]
print(ans)