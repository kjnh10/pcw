import math
import fractions
a,b,n=[int(input()) for _ in [0]*3]
c=a*b//fractions.gcd(a,b)
print(c*math.ceil(n/c))