N = int(input())
a = list(map(int, input().split()))
b = [1] * N

for k in range(1,N):
    if a[k-1] < a[k]:
        b[k] += b[k-1]

print(sum(b))