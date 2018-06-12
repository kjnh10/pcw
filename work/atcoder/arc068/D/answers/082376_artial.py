n = int(input())
a = set(map(int, input().split()))
r = len(a)
if r % 2 != n % 2:
    r -= 1
print(r)