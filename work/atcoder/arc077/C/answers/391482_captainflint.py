from collections import deque


n = int(input())
a = list(map(int, input().split()))
b = deque()
for i in range(n):
    if i % 2:
        b.appendleft(a[i])
    else:
        b. append(a[i])
if n % 2:
    b.reverse()
print(' '.join(map(str, b)))