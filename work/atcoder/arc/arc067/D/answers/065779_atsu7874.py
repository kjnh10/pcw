n, a, b = map(int, input().split())
x = list(map(int, input().split()))
total = 0
for i in range(n-1):
    if a * (x[i+1] - x[i]) > b:
        total += b
    else:
        total += a * (x[i+1] - x[i])
print(total)