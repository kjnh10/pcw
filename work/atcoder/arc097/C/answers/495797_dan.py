S = input()
K = int(input())

s = set()
for i in range(1, 6):
    for j in range(len(S)):
        if i + j <= len(S):
            s.add(S[j:j + i])

ans = list(sorted(s))[K - 1]

print(ans)
