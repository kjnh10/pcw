a, b, c = list(map(int, input().split()))
k = int(input())

m = max(a, b, c)
print(a + b + c - m + (m << k))
