import math
N, A, B = map(int, input().split())
a = [int(input()) for n in range(N)]
lb, ub = math.ceil(min(a)/A), math.ceil(max(a)/B)
while ub - lb > 1:
    mid = (lb + ub) // 2
    total = 0
    for n in a:
        total += max(0, math.ceil((n-(B*mid)) / (A-B)))

    if mid >= total:
        ub = mid
    else:
        lb = mid
print(ub)