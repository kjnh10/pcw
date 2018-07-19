N = int(input())
A,B = zip(*(map(int,input().split()) for _ in range(N)))

c = min((b for a,b in zip(A,B) if a > b), default=None)
if c is None:
  print(0)
else:
  print(sum(A)-c)