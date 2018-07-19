N,S,T = map(int, input().split())
A = [int(input()) for _ in range(N)]

W = 0
cnt = 0
for a in A:
  W += a
  if S <= W <= T:
    cnt += 1

print(cnt)