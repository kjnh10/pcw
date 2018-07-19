from collections import *
k=int(input())
q=deque([(1,1)])
v=[0]*(k+1)
while True:
    i,c=q.popleft()
    if i==0:
        break
    if v[i]:
        continue
    v[i]=True
    q.append(((i+1)%k,c+1))
    q.appendleft(((i*10)%k,c))
print(c)