n = int(input())
ss = []
for i in range(n):
    s = list(input())
    s.sort()
    ss.append(s)
ans = []
ans = ss[0]
for i in range(n):
    for j in ans:
        if ss[i].count(j) < ans.count(j):
            ans.remove(j)
for i in range(n):
    for j in ans:
        if ss[i].count(j) < ans.count(j):
            ans.remove(j)
print(''.join(ans))
