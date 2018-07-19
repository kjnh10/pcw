n,k = map(int,input().split())
a = list(map(int,input().split()))
l = [0]*200000
for i in a:
    l[i-1] += 1
l = sorted(l)
s = len(list(set(a)))
ret = 0
for i in range(s-k):
    ret += l[-s+i]
print(ret)
