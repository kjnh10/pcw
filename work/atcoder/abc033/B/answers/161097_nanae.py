import sys

def solve():
    N = int(input())
    s, p = [], []

    for i in range(N):
        name, num = input().split()
        s.append(name)
        p.append(int(num))

    tot = sum(p)

    for i in range(N):
        if 2 * p[i] > tot:
            print(s[i])
            return

    print('atcoder')
    


def debug(x, table):
    for name, val in table.items():
        if x is val:
            print('DEBUG:{} -> {}'.format(name, val), file=sys.stderr)
            return None

if __name__ == '__main__':
    solve()