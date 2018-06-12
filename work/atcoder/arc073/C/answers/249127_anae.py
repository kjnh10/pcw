import sys

def solve():
    N, T = map(int, input().split())
    ts = [int(i) for i in input().split()]

    cur = ts[0]
    ans = 0

    for ti in ts[1:]:
        ans += min(T, ti - cur)
        cur = ti

    ans += T

    print(ans)


if __name__ == '__main__':
    solve()