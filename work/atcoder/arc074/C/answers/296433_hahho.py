H,W = map(int, input().split())

# 4 cases

from math import floor, ceil

f = lambda x,y,z: max(x,y,z) - min(x,y,z)

def vals(H,W):
  yield (ceil(W/3)-floor(W/3))*H
  yield f(ceil(W/3)*H, (W-ceil(W/3))*floor(H/2), (W-ceil(W/3))*ceil(H/2))
  yield f(floor(W/3)*H, (W-floor(W/3))*floor(H/2), (W-floor(W/3))*ceil(H/2))


print(min(min(vals(H,W)), min(vals(W,H))))