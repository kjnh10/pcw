N,R = map(int,input().split())
S = input()
remain = S.count('.')
if remain == 0:
    print(0)
    exit()

s = list(S)
ans = 0
for i in range(N):
    paint = s[i:i+R].count('.')
    if paint == remain:
        ans += 1
        break
    if s[i] == '.':
        for j in range(i,i+R):
            s[j] = 'o'
        remain -= paint
        ans += 1
    ans += 1

print(ans)
