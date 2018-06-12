def solve():
    n = int(input())
    a = []
    b = []
    c = []
    d = []
    for i in range(n):
        a_, b_ = map(int, input().split())
        a.append(a_)
        b.append(b_)

    for i in range(n):
        c_, d_ = map(int, input().split())
        c.append(c_)
        d.append(d_)

    import numpy as np
    a, b, c, d = np.array(a), np.array(b), np.array(c), np.array(d)

    arg = np.argsort(b)[::-1]
    a = a[arg]
    b = b[arg]

    argc = np.argsort(c)
    c = c[argc]
    d = d[argc]


    n_pair = 0
    for i in range(n):
        c_, d_ = c[i], d[i]
        for j, a_ in enumerate(a):
            b_ = b[j]
            if a_ < c_ and b_ < d_:
                n_pair += 1
                a = np.delete(a, j)
                b = np.delete(b, j)
                #print(a_, b_, c_, d_)
                break

    print(n_pair)

solve()