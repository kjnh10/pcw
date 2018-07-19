n, c = map(int, input().split())
X = []
V = []
right = []
rightleft = []
calsum = 0
for i in range(n):
    x, v = map(int, input().split())
    X.append(x)
    V.append(v)
    calsum += v
    right.append(calsum-x)
    rightleft.append(calsum-2*x)

left = []
leftright = []
calsum = 0
for i in range(n):
    calsum += V[n-i-1]
    left.append(calsum - (c-X[n-i-1]))
    leftright.append(calsum - 2*(c-X[n-i-1]))

m = 0
M = 0
for i in range(0, n-1):
    m = max(m, left[i])
    M = max(M, m + rightleft[n-i-2])

mm = 0
MM = 0
for i in range(0, n-1):
    mm = max(mm, right[i])
    MM = max(MM, mm + leftright[n-i-2])

print(max(max(right), max(left), M, MM, 0))
