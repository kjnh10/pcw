import sys

stdin = sys.stdin


def na(): return map(int, stdin.readline().split())


def ns(): return stdin.readline().strip()


n,a,b=na()
v = list(na())
v.sort()
tot = 0
last = 0
for i in range(a):
    tot += v[-(i+1)]
    last = v[-(i+1)]

com = []
q = 100
for i in range(q):
    com.append([0]*q)

for i in range(q):
    com[i][0] = 1
    for j in range(1, q):
        com[i][j] = com[i-1][j-1] + com[i-1][j]

print("{:.9f}".format(tot/a))
lct = 0
large = 0
for w in v:
    if w > last:
        large += 1
    if w == last:
        lct += 1
ret = 0
if large == 0:
    for i in range(a,b+1):
        if 0 <= i-large <= lct:
            ret += com[lct][i-large]
else:
    ret = com[lct][a-large]
print(ret)
