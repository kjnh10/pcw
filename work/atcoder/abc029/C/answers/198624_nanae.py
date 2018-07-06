import sys

def solve():
    def dfs(length, n, s):
        if length == n:
            print(s)
            return

        dfs(length + 1, n, s + 'a')
        dfs(length + 1, n, s + 'b')
        dfs(length + 1, n, s + 'c')

    n = int(input())

    dfs(0, n, '')

def debug(x, table):
    for name, val in table.items():
        if x is val:
            print('DEBUG:{} -> {}'.format(name, val), file=sys.stderr)
            return None

if __name__ == '__main__':
    solve()