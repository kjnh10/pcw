N, M = map(int, input().split())
p = list(map(lambda x: int(x) -1 , input().split()))
class UnionFind:
    def __init__(self, n):
        self.data = [-1] * n
    def union(self, x, y):
        x,y = self.root(x), self.root(y)
        if x != y :
            if self.data[y] < self.data[x]:
                x,y = y,x
            self.data[x] += self.data[y]
            self.data[y] = x
        return x != y
    def root(self, x):
        if self.data[x] < 0 :
            return x
        self.data[x] = self.root(self.data[x])
        return self.data[x]
    def findSet(self, x, y):
        return self.root(x) == self.root(y)
uf = UnionFind(N)
for _ in range(M):
    px,py = map(int, input().split())
    px -= 1
    py -= 1
    uf.union(px,py)
ans = 0
for i, v in enumerate(p):
    ans += 1 if uf.findSet(v,i) else 0
print(ans)
