N, S, T = map(int, input().split())
A = list()
W = int(input())
cnt = 0
for i in range(0, N-1):
    A.append(int(input()))

if S <= W and T >= W:
    cnt += 1
for i in range(0, N-1):
    W += A[i]
    if S <= W and T >= W:
        cnt += 1

print(cnt)