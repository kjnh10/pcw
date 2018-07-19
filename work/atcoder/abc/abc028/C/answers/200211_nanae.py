import sys

def solve():
    def dfs(choice, v, s, mask):
        if choice == 3:
            s.add(v)
            return

        for i in range(len(a)):
            if not(mask & (1 << i)):
                dfs(choice + 1, v + a[i], s, mask ^ (1 << i))

    a = [int(i) for i in input().split()]
    s = set()

    dfs(0, 0, s, 0)

    s = sorted(s, reverse=True)

    print(s[2])

def debug(x, table):
    for name, val in table.items():
        if x is val:
            print('DEBUG:{} -> {}'.format(name, val), file=sys.stderr)
            return None

if __name__ == '__main__':
    solve()