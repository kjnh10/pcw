a,b,c,d,e,f = map(int,input().split())


from itertools import product
water = set()

for i,j in product(range(f//(a*100)+2),range(f//(100*b)+2)):
  n = a*i+b*j
  if n <= f:
    water.add(n)

water = sorted(water)

salt = set()

for i,j in product(range(f//c+2),range(f//d+2)):
  n = c*i+d*j
  if n <= f:
    salt.add(n)

salt = sorted(salt)

from bisect import bisect_left



bs,bw = 0,min(a,b)
for s in salt:
  w = s/e
  i = bisect_left(water,w)
  if i >= len(water):
    break
  w = water[i]
  if 100*w + s > f:
    break
  if bs*w < bw*s:
    bs,bw = s,w

print(bs+100*bw,bs)
