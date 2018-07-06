n = int(input())
pool = [0] * 10000002
ans = []

for i in range(n):
    x, y = map(int, input().split())
    pool[x] += 1
    pool[y+1] -= 1
j = 0
for i in pool:
    ans.append(j+i)
    j += i

print(max(ans))