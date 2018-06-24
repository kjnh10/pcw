k, s = [int(i) for i in input().split()]
result = 0
for x in range(k + 1):
    for y in range(k + 1):
        if 0 <= s - x - y <= k:
            result += 1
print(result)
