N = int(input())
S = input()
res = 0
for i in range(N):
    S_A = set(S[:i])
    S_B = set(S[i:])
    res = max(res, len(S_A & S_B))
print(res)