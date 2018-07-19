n = int(input())
A = list(map(int,input().split()))

S = sorted(A)
x,y = S[len(A)//2-1], S[len(A)//2]

for a in A:
  if a <= x:
    print(y)
  else:
    print(x)