from collections import deque

n = int(input())
a = list(map(int, input().split()))

b = deque()

for i in range(len(a)):
    if i % 2 == 0:
        b.append(str(a[i]))
    else:
        b.appendleft(str(a[i]))
    last = i

if last % 2 == 0:
    b.reverse()

print(' '.join(b))
