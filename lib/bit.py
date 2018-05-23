# Binary Indexd Tree
class BIT():
    def __init__(self, N):
        self.data = [0]*(N+1)  # 1-indexed, 0 not used

    def sum(self, n):
        s = 0
        while n > 0:
            s += self.data[n]
            n -= (n & -n)
        return s

    def add(self, n, x):
        while n <= N:
            self.data[n] += x
            n += (n & -n)


# バブルソートの交換回数
N = 4
A = [3,1,4,2]
bit = BIT(N)
ans = 0
for j in range(N):
    ans += j - bit.sum(j)
    bit.add(A[j], 1)
print(ans)

