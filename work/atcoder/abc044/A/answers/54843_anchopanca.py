from sys import stdin

n = int(stdin.readline())
k = int(stdin.readline())
x = int(stdin.readline())
y = int(stdin.readline())

first = min(n, k)
second = n - k
if second < 0:
    second = 0

print(x * first + y * second)
