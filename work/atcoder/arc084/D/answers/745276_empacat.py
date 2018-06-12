from collections import deque
k = int(input().strip())
a = [k+1] * k
q = deque()
q.append((1, 1))
while q:
    i, m = q.popleft()
    while 1:
        if a[i] <= m:
            break
        if i == 0:
            print(m)
            raise SystemExit
        a[i] = m
        q.append(((i+1)%k, m+1))
        i = i * 10 % k
