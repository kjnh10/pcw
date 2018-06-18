n,m,x=[int(x) for x in input().split()]
a=[int(x) for x in input().split()]
l=0
r=0
for i in a:
  if i < x:
    l += 1
  else:
    r += 1

print(min(l,r))