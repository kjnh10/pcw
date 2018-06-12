N = int(input())
*A, = map(int, input().split())
A.sort()
n = A[-1]
k = 0
for a in A[:-1]:
    if k < min(a, n-a):
        k = a
print(n, k)
