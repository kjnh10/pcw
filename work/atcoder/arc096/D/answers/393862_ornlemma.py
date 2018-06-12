import sys

cin = sys.stdin
# cin = open("in.txt", "r")

def line2N():
    return map(int, cin.readline().split())

n, c = line2N()
x = [0]*n
v = [0]*n
for i in range(n):
    x0, v0 = line2N()
    x[i] = x0
    v[i] = v0
c1 = [0]*n
m1 = [0]*(n+1)
c1[0] = -(x[0]-0) + v[0]
m1[0] = max(0, c1[0])
for i in range(1,n):
    c1[i] = c1[i-1] - (x[i]-x[i-1]) + v[i]
    m1[i] = max(m1[i-1], c1[i])
c2 = [0]*n
c2[n-1] = -(c - x[n-1]) + v[n-1]
m2 = [0]*(n+1)
m2[n-1] = max(0, c2[n-1])
for i in range(n-2, -1, -1):
    c2[i] = c2[i+1] - (x[i+1]-x[i]) + v[i]
    m2[i] = max(m2[i+1], c2[i])
ans0 = 0
for i in range(0, n-1):
    ans0 = max(ans0, c1[i] - x[i] + m2[i+1])
for i in range(n-1, 0, -1):
    ans0 = max(ans0, c2[i] - (c-x[i]) + m1[i-1])

print(max(ans0, m1[n-1], m2[0]))
