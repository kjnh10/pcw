import sys

def solve():
    n, m = map(int, input().split())
    tan = (n % 12) * 30 + m / 2
    tyo = 6.0 * m

    ans = min((tan - tyo) % 360, (tyo - tan) % 360)

    print(ans)

def debug(x, table):
    for name, val in table.items():
        if x is val:
            print('DEBUG:{} -> {}'.format(name, val), file=sys.stderr)
            return None

if __name__ == '__main__':
    solve()