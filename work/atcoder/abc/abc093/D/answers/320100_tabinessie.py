import numpy as np

q = int(input())

for _ in range(q):
    a, b = sorted(list(map(int, input().split(' '))))
    n = int(np.floor(np.sqrt(a * b)))

    cnt = (n - 1) * 2

    if a != b:
        if a == n:
            if n * (n + 1) < a * b:
                cnt += 1
        else:
            cnt += 1
            if n ** 2 == a * b:
                cnt -= 1
            if n * (n + 1) >= a * b:
                cnt -= 1

    print(cnt)