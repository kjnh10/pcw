from collections import deque
arr = deque()
prev = None
num = 0
for c in input():
  if prev is not None and c != prev:
    arr.append(num)
    num = 0
  prev = c
  num += 1
arr.append(num)

while len(arr) > 2:
  if arr[0] > arr[-1]:
    v = arr.pop()
    v += arr.pop()
    arr.append(v)
  else:
    v = arr.popleft()
    v += arr.popleft()
    arr.appendleft(v)

print(max(arr))