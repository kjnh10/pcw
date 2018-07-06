import math, sys

sys.setrecursionlimit(10 ** 8)

a, b, c = map(int, input().split())

"""
a*t + b*sin(c*pi*t) - 100 = 0

diff
a + b*c*pi*cos(c*pi*t) = 0

"""
t = 1
f = 1
cm = c * math.pi
bcm = b * cm
mi = 0
ma = 10**6
while abs(f) > 10e-10:
    t = (mi + ma) / 2
    f = a * t + b * math.sin(cm * t) - 100
    if f < 0:
        mi = t
    elif f > 0:
        ma = t
else:
    print(t)
