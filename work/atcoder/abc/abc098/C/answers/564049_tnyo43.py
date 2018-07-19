n = int(input())
S = list(map(lambda x: 1 if x=='E' else 0, list(input())))

for i in range(1, n):
    S[i] += S[i-1]

S.insert(0, 0)
ans = n
for i in range(1, n+1):
    c = i-S[i-1]-1
    # print(c)
    c += S[-1]-S[i]
    ans = min(ans, c)
print(ans)
