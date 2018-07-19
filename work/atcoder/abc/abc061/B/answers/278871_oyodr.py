N, M = map(int, input().split())
A = [0] * N
for i in range(M):
    a, b = map(int, input().split())
    a -= 1
    b -= 1
    A[a] += 1
    A[b] += 1
for i in range(N):
    print(A[i])
