input()
x=[int(x) for x in input().split()]
y=sorted(x)
l=y[len(x)//2-1]
r=y[len(x)//2]
for xi in x:
  if xi < r:
    print(r)
  else:
    print(l)