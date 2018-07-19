import sys

stdin = sys.stdin

ni = lambda: int(ns())
na = lambda: list(map(int, stdin.readline().split()))
ns = lambda: stdin.readline()

s = list(ns().strip())
t = ns().strip()


def ok(s, t):
    if len(s) < len(t):
        return False
    for i in range(len(s) - len(t) + 1):
        o = 1
        for j in range(len(t)):
            if s[i + j] != '?' and s[i + j] != t[j]:
                o = 0
        if o == 1:
            return True
    return False


if not ok(s, t):
    print("UNRESTORABLE")
    sys.exit(0)

for i in range(len(s)):
    if s[i] == '?':
        for j in range(97,97+26):
            s[i] = chr(j)
            if ok(s, t):
                break

print("".join(s))