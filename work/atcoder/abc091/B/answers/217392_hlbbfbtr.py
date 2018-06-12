N = int(input())
S = [input() for _ in range(N)]
M = int(input())
T = [input() for _ in range(M)]

result = 0
for s in S:
    score = S.count(s) - T.count(s)
    if result < score:
        result = score
print(result)
