import sys

def solve():
    N, M = map(int, input().split())
    st = [[int(i) for i in input().split()] for j in range(N)]
    cp = [[int(i) for i in input().split()] for j in range(M)]

    for a, b in st:
        ans = 0
        min_len = 10**9

        for i, (c, d) in enumerate(cp):
            tmp = abs(c - a) + abs(d - b)
            if tmp < min_len:
                min_len = tmp
                ans = i + 1

        print(ans)


def debug(x, table):
    for name, val in table.items():
        if x is val:
            print('DEBUG:{} -> {}'.format(name, val), file=sys.stderr)
            return None

if __name__ == '__main__':
    solve()