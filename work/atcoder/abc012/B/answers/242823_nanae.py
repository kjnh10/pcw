import sys

def solve():
    n = int(input())
    h = n // 3600
    m = (n % 3600) // 60
    s = (n % 60)

    ans = '{:02d}:{:02d}:{:02d}'.format(h, m, s)

    print(ans)

if __name__ == '__main__':
    solve()