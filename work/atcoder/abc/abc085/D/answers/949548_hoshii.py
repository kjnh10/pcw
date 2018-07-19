import math
N, H = map(int, input().split())
A = []
r = []
for _ in range(N):
    a, b = map(int, input().split())
    A.append([a, 0])
    A.append([b, 1])
A.sort()
ans = 0
while H > 0:
    p = A.pop()
    if p[1] == 1:
        H -= p[0]
        ans += 1
    else:
        ans += math.ceil(H / p[0])
        break
print(ans)
