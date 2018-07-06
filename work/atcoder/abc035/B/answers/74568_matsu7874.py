import collections
s=input()
t=int(input())
cnt = collections.Counter()
for c in s:
    cnt[c] += 1
dist = abs(cnt['L'] - cnt['R']) + abs(cnt['U'] - cnt['D'])
if t==1:
    print(dist + cnt['?'])
else:
    if dist >= cnt['?']:
        print(dist - cnt['?'])
    else:
        if (cnt['?']-dist)%2==0:
            print(0)
        else:
            print(1)
