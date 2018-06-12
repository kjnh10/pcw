from fractions import gcd
def lcm(a, b):
    return a * b // gcd (a, b)
def f():
    n = int(input())
    a=[]
    l=1
    for i in range(n):
        s=(int(input()))
        l=lcm(l,s)
    print(l)
f()