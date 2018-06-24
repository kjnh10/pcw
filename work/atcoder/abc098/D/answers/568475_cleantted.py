N = int(input())
A = list(map(int, input().split()))

r = 0
xorsum = 0
sum = 0
count = 0
for l in range(N):
    while (r != N and sum + A[r] == xorsum ^ A[r]):
        sum += A[r]
        xorsum ^= A[r]
        r += 1

    count += r - l
    sum -= A[l]
    xorsum ^= A[l]

print(count)