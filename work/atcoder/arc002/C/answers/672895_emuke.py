n = int(input())
s = list(input())
l = ['A','B','X','Y']
d = []
for i in range(4):
    for j in range(4):
        d.append(l[i]+l[j])
ans = 0
for i in range(len(d)-1):
    for j in range(i+1,len(d)):
        c = 0
        k=0
        while k < n-1:
            if s[k]+s[k+1] == d[i] or s[k]+s[k+1] == d[j]:
                c += 1
                k += 2
                ans = max(c,ans)
            else:
                k += 1

print(n-ans)