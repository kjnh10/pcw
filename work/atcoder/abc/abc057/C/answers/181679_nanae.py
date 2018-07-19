import sys

def solve():
    N = int(input())
    ans = 20

    for a in range(1, N + 1):
        if a**2 > N:
            break
        if N % a:
            continue

        b = N // a
        # print(a, b)
        f = max(len(str(a)), len(str(b)))
        ans = min(ans, f)

    print(ans)


def debug(x, table):
    for name, val in table.items():
        if x is val:
            print('DEBUG:{} -> {}'.format(name, val), file=sys.stderr)
            return None

if __name__ == '__main__':
    solve()