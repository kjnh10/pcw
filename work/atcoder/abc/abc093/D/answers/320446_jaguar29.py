from math import sqrt

Q = int(input())

for i in range(Q):
    A, B = list(map(int, input().split()))

    sq = sqrt(A*B)
    sq_int = int(sq)

    ans = sq_int*2 - 2
    if sq_int**2==A*B and A!=B:
        ans -= 1
    if sq_int*(sq_int+1)<A*B:
        ans += 1

    #print(A*B, sq_int)
    print(ans)
