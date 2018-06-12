N, M = map(int, input().split())

A = []
for _ in range(N):
  A.append(input().strip())
B = []
for _ in range(M):
  B.append(input().strip())

def f():
  for i in range(N - M + 1):
    for j in range(N - M + 1):
      same = True
      for ii in range(M):
        for jj in range(M):
          if B[ii][jj] != A[i + ii][j + jj]:
            same = False
      if same:
        print("Yes")
        return 
  print("No")

f()
