ans = 0
n = int(input())

for i in range(n+1):
    ans += i * 10000

print(ans // n)
