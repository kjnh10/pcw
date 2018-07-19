N, K = map(int, input().split())
a = list(map(int, input().split()))

psum = sum(a[:K])
total = psum
for i in range(K, N):
    psum += a[i] - a[i-K]
    total += psum
print(total)
