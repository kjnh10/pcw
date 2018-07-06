import sys

def solve():
    x, y = map(int, input().split())

    if x - y > 0:
        ans = 'Worse'
    else:
        ans = 'Better'

    print(ans)


def debug(x, table):
    for name, val in table.items():
        if x is val:
            print('DEBUG:{} -> {}'.format(name, val), file=sys.stderr)
            return None

if __name__ == '__main__':
    solve()