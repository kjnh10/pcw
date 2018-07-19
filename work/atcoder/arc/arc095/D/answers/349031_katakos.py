import bisect

n = int(input())
aaa = list(map(int, input().split()))
aaa.sort()
m = aaa[-1]
ri = bisect.bisect(aaa, m // 2)
if ri == 0:
    print(m, aaa[0])
else:
    r1, r2 = aaa[ri - 1], aaa[ri]
    d1 = m - 2 * r1
    d2 = 2 * r2 - m
    if d1 <= d2:
        print(m, r1)
    else:
        print(m, r2)
