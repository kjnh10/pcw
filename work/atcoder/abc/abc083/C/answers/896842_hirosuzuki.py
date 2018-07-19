import sys

line = sys.stdin.readline().strip()
X, Y = [int(x) for x in line.split()]

n = X
r = 0
while 1:
    if n > Y:
        break
    n *= 2
    r += 1

print(r)
