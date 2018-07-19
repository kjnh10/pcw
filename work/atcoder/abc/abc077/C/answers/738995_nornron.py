N = int(input())
A = list(map(int, input().split()))
B = list(map(int, input().split()))
C = list(map(int, input().split()))

A.sort()
B.sort()
C.sort()
C.reverse()

ans = 0
ai = 0
ci = N-1
for b in B:
    while ai < N and A[ai] < b:
        ai += 1
    while ci >= 0 and C[ci] <= b:
        ci -= 1
    ans += ai * (ci+1)

print(ans)