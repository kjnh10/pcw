import sys

def solve():
    N = int(input())

    if N < 60:
        print('Bad')
    elif N < 90:
        print('Good')
    elif N < 100:
        print('Great')
    else:
        print('Perfect')


def debug(x, table):
    for name, val in table.items():
        if x is val:
            print('DEBUG:{} -> {}'.format(name, val), file=sys.stderr)
            return None

if __name__ == '__main__':
    solve()