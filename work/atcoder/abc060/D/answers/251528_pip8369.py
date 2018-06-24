# -*- coding: utf-8 -*-
(N,W) = map(int,input().split(" "))

w = []
v = []

for i in range(N):
    item = list(map(int,input().split(" ")))
    w.append(item[0])
    v.append(item[1])


nap_memo = {}

def nap(i,j):
    key = str(i)+':'+str(j)
    if key in nap_memo:
        return nap_memo[key]
    r = 0
    if i == N:
        r= 0
    elif j < w[i]:
        r= nap(i+1,j)
    else:
        r= max([nap(i+1,j),nap(i+1,j-w[i])+v[i]])

    nap_memo[key] = r
    return r

print(nap(0,W))