from math import ceil,log2

class Btree(object):  # {{{
    def __init__(self, N):  # N:要素数
        self.depth = ceil(log2(N)) + 1
        self.nodeN = (1 << self.depth) - 1
        self.ls = 2**(self.depth-1)-1  # leaf start
        self.le = 2**(self.depth  )-1  # leaf end + 1
        self.leafs = range(self.ls, self.le)
        self.data = [0] * (self.nodeN)  # 深さdepthの二分木

        # 区間の初期化
        self.ranges = [(0,0)] * ((1 << self.depth) - 1)  # [l, r)
        self.__set_range(0, 0, N)

    def parent(self, v): return ceil((v-2)/2)
    def chl(self, v): return 2*v + 1
    def chr(self, v): return 2*v + 2
    def isleaf(self, v):
        if 2**(self.depth-1)-1 <= v:
            return True
        else:
            return False

    def __set_range(self, v, l, r):
        self.ranges[v]= (l, r)
        m = ceil((l+r)/2)
        left = self.chl(v)
        right = self.chr(v)

        self.ranges[left]= (l, m)
        if not self.isleaf(left):
            self.__set_range(left, l, m)

        self.ranges[right]= (m, r)
        if not self.isleaf(right):
            self.__set_range(right, m, r)
# }}}

class SegTree(Btree):  # {{{
    def __init__(self, A):  # A:数列
        N = len(A)
        super().__init__(N)

        # 葉の初期化
        for n in range(N):
            self.data[self.ls + n] = A[n]

        self.rec_calc(0)

    def __op(self,a,b):
        return min(a,b) #RMQ

    def rec_calc(self, v):
        if self.isleaf(v):
            return self.data[v]
        else:
            a = self.rec_calc(self.chl(v))
            b = self.rec_calc(self.chr(v))
            self.data[v] = self.__op(a,b)
            return self.data[v]

    def change(self, i, x):
        pass

    def query(self, l, r):
        pass

# }}}

# test
if __name__ == '__main__':
    bt = Btree(16)
    print('depth', bt.depth)
    print(bt.ranges[0])
    print(bt.ranges[5])

    st = SegTree([5,3,7,9,6,4,1,2])
    print(st.data[5])

