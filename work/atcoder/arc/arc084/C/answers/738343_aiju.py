from bisect import bisect_right

N = int(input())
A = list(map(int, input().split()))
B = list(map(int, input().split()))
C = list(map(int, input().split()))
B.sort()
C.sort()

BN = []
for b in B:
    i = bisect_right(C, b)
    BN.append(N - i)
for i in range(N - 2, -1, -1):
    BN[i] += BN[i + 1]
BN.append(0)
s = 0
for a in A:
    i = bisect_right(B, a)
    s += BN[i]
print(s)
