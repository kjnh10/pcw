A,B,C,D=map(int,input().split())
if B*C > D*A:
  print("TAKAHASHI")
elif B*C < D*A:
  print("AOKI")
else:
  print("DRAW")
