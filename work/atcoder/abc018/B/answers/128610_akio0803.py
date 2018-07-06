S = list(input())
N = int(input())

for i in range(N):
    l, r = [int(_) for _ in input().split()]
    mid = (r - l) // 2
    for j in range(mid + 1):
        S[l + j - 1], S[r - j - 1] = S[r - j - 1], S[l + j - 1]


print("".join(S))
