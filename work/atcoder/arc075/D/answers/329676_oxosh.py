# D
import math
N, A, B = map(int, input().split())
H = []
for _ in range(N):
    H.append(int(input()))

def can_clear(n):
    res = 0
    for i in range(N):
        res += max(0, math.ceil((H[i] - B*n) / (A - B)))
    if res > n:
        return False
    else:
        return True


# search
# 0:False
# NR:True
NR = math.ceil(max(H) / B)
NL = 0
while True:
    NM = math.ceil((NR + NL) / 2)
    if NM == NR:
        break
    if can_clear(NM):
        NR = NM
    else:
        NL = NM
print(NM)