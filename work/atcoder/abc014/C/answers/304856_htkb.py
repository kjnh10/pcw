n = int(input())
ar = [0]*1000002
for i in range(n):
    a, b = map(int, input().split())
    ar[a] += 1
    ar[b+1] -= 1
ar = list(filter(lambda n:n, ar))
result, total = 0, 0
for i in range(len(ar)):
    total += ar[i]
    result = max(result, total) 
print(result)