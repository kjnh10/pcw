import sys

def solve():
    l1, l2, l3 = map(int, input().split())
    a = [0] * (10 + 1)
    a[l1] += 1
    a[l2] += 1
    a[l3] += 1

    for i in range(len(a)):
        if a[i] & 1:
            print(i)
            return


def debug(x, table):
    for name, val in table.items():
        if x is val:
            print('DEBUG:{} -> {}'.format(name, val), file=sys.stderr)
            return None

if __name__ == '__main__':
    solve()