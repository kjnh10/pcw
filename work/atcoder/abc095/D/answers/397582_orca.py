n,c = map(int,input().split())
X = []
V = []
for i in range(n):
  x,v = map(int,input().split())
  X.append(x)
  V.append(v)
right = []
right2 = []
left = []
count = 0
left2 = []
for i in range(n):
  if i == 0:
    count += (V[i] - X[i])
    right.append(count)
    right2.append(count)
  else:
    count += (V[i] - (X[i] - X[i - 1]))
    right.append(count)
    right2.append(max(right2[-1],count))

count = 0
for i in range(n):
  if i == 0:
    count += (V[(i + 1) * (-1)] - (c - X[(i + 1) * (-1)]))
    left.append(count)
    left2.append(count)
  else:
    count += (V[(i + 1) * (-1)] - ((X[i * (-1)] - X[((i + 1) * (-1))])))
    left.append(count)
    left2.append(max(left2[-1],count))
ans = max(0,max(right),max(left))
for i in range(n - 1):
  ans = max(ans, right[i] - X[i] + left2[n-i-2])
for i in range(n - 1):
  ans = max(ans, left[i] - (c - X[(i + 1) * (-1)]) + right2[n-i-2])
print(ans)