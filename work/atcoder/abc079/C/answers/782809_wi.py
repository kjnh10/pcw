import sys

stdin = sys.stdin

ni = lambda: int(ns())
na = lambda: list(map(int, stdin.readline().split()))
ns = lambda: stdin.readline()

s = ns().strip()
a = [int(_) for _ in s]
# print(a)
for i in range(8):
    t = a[0]
    for j in range(3):
        if i>>j&1:
            t += a[j+1]
        else:
            t -= a[j+1]
    if t == 7:
        print("{}{}{}{}{}{}{}=7".format(
            a[0], "+" if i>>0&1 else "-",
            a[1], "+" if i >> 1 & 1 else "-",
            a[2], "+" if i >> 2 & 1 else "-",
            a[3],
        ))
        break
