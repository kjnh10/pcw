n = int(input())
s = [list(input()) for i in range(n)]
t = [ [""] * n for i in range(n)]

for i in range(n):
    for j in range(n):
        t[i][j] = s[j][n - 1 - i]

for line in t[::-1]:
    print("".join(map(str, line[::-1])))
