n,l=map(int,input().split())
x=1
a=0
for s in input():
 x+=1 if s=='+' else -1
 if x>l:
  a+=1
  x=1
print(a)