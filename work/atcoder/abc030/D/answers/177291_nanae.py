import sys

def solve():
    N, a = map(int, input().split())
    a -= 1
    k = int(input())
    b = [int(i) - 1 for i in input().split()]

    pos = a
    visited = [-1] * N
    visited[pos] = 0
    num = 1

    while visited[b[pos]] == -1:
        pos = b[pos]
        visited[pos] = num
        num += 1

    len_cyc = num - visited[b[pos]]
    pos = b[pos]
    is_cyc = [False] * N

    for i in range(len_cyc):
        is_cyc[pos] = True
        pos = b[pos]

    # print(is_cyc)

    step = 0
    pos = a

    while not is_cyc[pos]:
        pos = b[pos]
        step += 1

        if step == k:
            print(pos + 1)
            quit()

    step = (k - step) % len_cyc

    for i in range(step):
        pos = b[pos]

    print(pos + 1)


def debug(x, table):
    for name, val in table.items():
        if x is val:
            print('DEBUG:{} -> {}'.format(name, val), file=sys.stderr)
            return None

if __name__ == '__main__':
    solve()