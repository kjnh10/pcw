N = int(input())

li = list(map(int, input().split()))
num = 0

for i in range(N):
    if li[i] < 80:
        num += (80-li[i])

print(num)
