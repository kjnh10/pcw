from sys import stdin, stdout, stderr

def solve():
    a, d = map(int, input().split())

    if (a + 1) * d < a * (d + 1):
        ans = a * (d + 1)
    else:
        ans = (a + 1) * d

    print(ans)

def debug(x, table):
    for name, val in table.items():
        if x is val:
            print('DEBUG:{} -> {}'.format(name, val), file=stderr)
            return None

if __name__ == '__main__':
    solve()