import sys
from itertools import permutations

def debug(x, table):
    for name, val in table.items():
        if x is val:
            print('DEBUG:{} -> {}'.format(name, val), file=sys.stderr)
            return None

def solve():
    N, M = map(int, input().split())
    Adj = [[0]*N for i in range(N)]

    for i in range(M):
        a, b = map(int, input().split())
        a -= 1
        b -= 1
        Adj[a][b] = 1
        Adj[b][a] = 1

    cnt = 0

    for line in permutations(range(1, N)):
        path = [0] + list(line)
        # debug(path, locals())

        for i in range(N - 1):
            if not Adj[path[i]][path[i + 1]]:
                break
        else:
            cnt += 1

    print(cnt)


if __name__ == '__main__':
    solve()