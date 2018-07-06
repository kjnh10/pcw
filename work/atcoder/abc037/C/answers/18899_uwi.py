import sys

stdin = sys.stdin

n,k = map(int, stdin.readline().split())
a = list(map(int, stdin.readline().split()))
cum = [0]
for v in a:
    cum.append(cum[-1] + v)
s = 0
for i in range(n-k+1):
    s += cum[i+k]-cum[i]
print(s)