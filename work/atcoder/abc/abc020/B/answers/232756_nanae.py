import sys

def solve():
    a, b = map(int, input().split())
    ans = int(str(a) + str(b)) * 2
    print(ans)

if __name__ == '__main__':
    solve()