class UnionFind:
    def __init__(self, n):
        self.table = [-1] * n

    def _root(self, x):
        if self.table[x] < 0:
            return x
        else:
            self.table[x] = self._root(self.table[x])
            return self.table[x]

    def find(self, x, y):
        return self._root(x) == self._root(y)

    def union(self, x, y):
        r1 = self._root(x)
        r2 = self._root(y)
        if r1 == r2:
            return
        # ランクの取得
        d1 = self.table[r1]
        d2 = self.table[r2]
        if d1 <= d2:
            self.table[r2] = r1
            if d1 == d2:
                self.table[r1] -= 1
        else:
            self.table[r1] = r2


n, m = map(int, input().split())
uft = UnionFind(n)
ppp = list(map(int, input().split()))
rev = {x: i for i, x in enumerate(ppp)}

for _ in range(m):
    x, y = map(int, input().split())
    x -= 1
    y -= 1
    uft.union(x, y)

ans = 0
for i, x in enumerate(ppp):
    if uft.find(i, x - 1):
        ans += 1

print(ans)
