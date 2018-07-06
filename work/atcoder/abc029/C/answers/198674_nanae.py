import sys
from itertools import product

def solve():
    n = int(input())

    for s in product('abc', repeat=n):
        print(''.join(s))

def debug(x, table):
    for name, val in table.items():
        if x is val:
            print('DEBUG:{} -> {}'.format(name, val), file=sys.stderr)
            return None

if __name__ == '__main__':
    solve()