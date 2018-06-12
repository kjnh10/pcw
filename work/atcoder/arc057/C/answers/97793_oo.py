A, K = map(int, input().split())
B = 2 * 10**12
if K == 0:
    print(B - A)
else:
    count = 0
    while A < B:
        A += 1 + K*A
        count += 1
    print(count)
