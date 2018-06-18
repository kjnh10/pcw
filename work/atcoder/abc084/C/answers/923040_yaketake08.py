n = int(input())
cur = [0]*n
for i in range(n-1):
    c, s, f = map(int, input().split())
    for j in range(i+1):
        cur[j] = max(s, (cur[j]+f-1)//f*f) + c
print(*cur, sep='\n')
