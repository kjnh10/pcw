n = int(input())
a = []
for i in range(n):
    n, m = map(int, input().split())
    a.append((n, 1))
    a.append((m+1, -1))
a.sort(reverse=True)
result, total = 0, 0
while a:
    j = a[-1][0]
    while a and j == a[-1][0]:
        total += a.pop()[1]
    result = max(result, total) 
print(result)