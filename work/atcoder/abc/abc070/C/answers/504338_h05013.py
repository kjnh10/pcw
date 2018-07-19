from fractions import gcd
def lcm(a,b): return a*b//gcd(a,b)

n = int(input())
res = 1
for i in range(n):
    t = int(input())
    res = lcm(res, t)
print(res)