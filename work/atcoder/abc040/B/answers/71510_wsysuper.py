n = int(input())
res = 1000000000000
i = 1
while i * i <= n:
    temp = abs(n // i - i) + n % i
    res = min(temp, res)
    i += 1
print(res)