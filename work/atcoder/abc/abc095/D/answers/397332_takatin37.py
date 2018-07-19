from collections import deque

def main():
    N,C = map(int, input().split())
    x = [0 for _ in range(N)]
    v = [0 for _ in range(N)]
    for i in range(N):
        x[i],v[i] = map(int, input().split())

    a = [0 for _ in range(N)]
    amax = 0
    b = [0 for _ in range(N)]
    bmax = 0
    cal1 = []
    cal2 = []
    for i in range(N):
        if i == 0:
            cal1.append(v[i]-x[i])
            cal2.append(v[-i-1]-(C-x[-i-1]))
            if amax < cal1[-1]:
                amax = cal1[-1]
            if bmax < cal2[-1]:
                bmax = cal2[-1]
        else:
            cal1.append(cal1[-1]+v[i]-abs(x[i]-x[i-1]))
            cal2.append(cal2[-1]+v[-i-1]-abs(x[-i-1]-x[-i]))
            if amax < cal1[-1]:
                amax = cal1[-1]
            if bmax < cal2[-1]:
                bmax = cal2[-1]
        a[i] = max([amax, cal1[-1]])
        b[i] = max([bmax, cal2[-1]])
    c = [0 for _ in range(N-1)]
    d = [0 for _ in range(N-1)]
    if c==[]:
        c.append(0)
        d.append(0)
    for i in range(N-1):
        c[i] = a[i] + b[-i-2] - x[i]
        d[i] = b[i] + a[-i-2] - (C-x[-i-1])
    return max([amax,bmax,max(c),max(d)])

if __name__ == '__main__':
    print(main())

