n = int(input())
la = list(map(int,input().split()))
if n%2 == 0:
  for i in range(n-1,-1,-2):
    print(la[i],end=' ')
  for i in range(0,n,2):
    print(la[i],end=' ')
  print()
else:
  for i in range(n-1,-1,-2):
    print(la[i],end=' ')
  for i in range(1,n,2):
    print(la[i],end=' ')
  print()