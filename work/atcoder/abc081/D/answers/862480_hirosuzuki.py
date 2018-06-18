import sys

line = sys.stdin.readline().strip()
N = int(line)
line = sys.stdin.readline().strip()
A = [int(x) for x in line.split()]

#N = 4
#A = [-2, -6, -1, -4]
#A = [0, 1, 0, 0]

#print(N)
#print(A)
vs = sorted([(x, i) for i, x in enumerate(A)])
k = vs[0] if abs(vs[0][0]) > abs(vs[-1][0]) else vs[-1]
#print(k)

tejun = []

def mv(i, j):
    tejun.append((i, j))
    A[j] += A[i]
    #print("*", i, j, A)

if k[0] > 0:
  mv(k[1], 0)
  mv(k[1], 0)
  for i in range(1, N):
      mv(i - 1, i)
      mv(i - 1, i)
elif k[0] < 0:
  mv(k[1], N - 1)
  mv(k[1], N - 1)
  for i in range(N, 1, -1):
      mv(i - 1, i - 2)
      mv(i - 1, i - 2)
else:
    pass

print(len(tejun))
for t in tejun:
    print(t[0] + 1, t[1] + 1)
