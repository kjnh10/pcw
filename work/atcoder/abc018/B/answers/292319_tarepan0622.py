s = input()
n = int(input())
for a, b in [list(map(int, input().split())) for x in range(n)]:
    s = s[:a - 1] + s[b - 1:a - 2 if a - 2 >= 0 else None:-1] + s[b:]
print(s)