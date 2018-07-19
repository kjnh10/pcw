N,M = map(int,input().split())
ps = list(map(lambda x:int(x)-1,input().split()))
xys = [tuple(map(lambda x:int(x)-1,input().split())) for i in range(M)]

class UnionFind:
    def __init__(self,N):
        self.parent = [i for i in range(N)]
        self.rank = [0] * N
    def root(self,a):
        if self.parent[a] == a:
            return a
        else:
            self.parent[a] = self.root(self.parent[a])
            return self.parent[a]
    def is_same(self,a,b):
        return self.root(a) == self.root(b)
    def unite(self,a,b):
        ra = self.root(a)
        rb = self.root(b)
        if ra == rb: return
        if self.rank[ra] < self.rank[rb]:
            self.parent[ra] = rb
        else:
            self.parent[rb] = ra
            if self.rank[ra] == self.rank[rb]: self.rank[ra] += 1

uf = UnionFind(N)
for x,y in xys:
    if uf.is_same(x,y): continue
    uf.unite(x,y)

ans = 0
for i,p in enumerate(ps):
    if i==p or uf.is_same(i,p):
        ans += 1
print(ans)
