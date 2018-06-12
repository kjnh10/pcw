import sys

def debug(x, table):
    for name, val in table.items():
        if x is val:
            print('DEBUG: {} -> {}'.format(name, val), file=sys.stderr)
            return None

x = int(input())

ans = (x // 11) * 2
x %= 11

if x > 0:
    if x > 6:
        ans += 2
    else:
        ans += 1

print(ans)