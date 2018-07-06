import sys

def solve():
    n = int(input())

    if n % 1111:
        ans = 'DIFFERENT'
    else:
        ans = 'SAME'

    print(ans)

def debug(x, table):
    for name, val in table.items():
        if x is val:
            print('DEBUG:{} -> {}'.format(name, val), file=sys.stderr)
            return None

if __name__ == '__main__':
    solve()