import math
Q = int(input())
for _ in range(Q):
    A, B = list(map(int, input().split()))

    div = A * B
    ca = int(math.sqrt(div))
    if ca == A:
        ca += 1
    result = ca - 1
    if A <= ca:
        result -= 1
    cand = float("inf")
    while True:
        if ca == A:
            ca += 1
        cb = min(div // ca, cand)
        if cb * ca == div:
            cb -= 1
        if cb == B:
            cb -= 1
        if cb == cand:
            result += cb - 1
            if B <= cand:
                result -= 1
            break
        cand = cb
        result += 1
        # print(ca, cand, result)
        ca += 1
        if cb == 1 or ca == 1:
            if B <= cand:
                result -= 1
            break
    print(result)
