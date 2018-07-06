from sys import stdin, stdout, stderr

def solve():
    L, H = map(int, input().split())
    N = int(input())

    for lp in range(N):
        A = int(input())

        if L <= A <= H:
            print(0)
        elif A < L:
            print(L - A)
        else:
            print(-1)

def debug(x, table):
    for name, val in table.items():
        if x is val:
            print('DEBUG:{} -> {}'.format(name, val), file=stderr)
            return None

if __name__ == '__main__':
    solve()