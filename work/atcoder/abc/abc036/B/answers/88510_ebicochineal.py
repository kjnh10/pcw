n = int(input())
s = [input() for x in range(n)]
for i in range(n):
    o = ""
    for j in range(n):
        o += s[n-j-1][i]
    print(o)