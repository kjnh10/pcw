n=int(input())
import heapq
a=list(map(int,input().split()))
q=a[:n]
heapq.heapify(q)
x=[sum(q)]
for k in range(n,2*n):
    v=heapq.heappushpop(q,a[k])
    x.append(x[-1]+a[k]-v)
a=a[::-1]
q=[-v for v in a[:n]]
heapq.heapify(q)
y=[-sum(q)]
for k in range(n,2*n):
    v=-heapq.heappushpop(q,-a[k])
    y.append(y[-1]+a[k]-v)
print(max(v-w for v,w in zip(x,y[::-1])))