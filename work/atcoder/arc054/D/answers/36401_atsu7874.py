p = float(input())
l = 0
r =100

def tmf(t):
    return p/(2**(t/1.5)) + t

while l+0.000000001 < r:
    t1 = (l*2 + r) / 3
    t2 = (l + r*2) / 3
    if tmf(t1) < tmf(t2):
        r = t2
    else:
        l = t1
print(tmf(l))
