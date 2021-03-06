import sys

def solve():
    n = int(input())
    s = input()

    if n % 2 == 0:
        print(-1)
        return

    t = (n - 1) // 2

    ss = 'b'

    for i in range(1, t + 1):
        if i % 3 == 1:
            ss = 'a' + ss + 'c'
        elif i % 3 == 2:
            ss = 'c' + ss + 'a'
        else:
            ss = 'b' + ss + 'b'

    if s != ss:
        print(-1)
    else:
        print(t)

if __name__ == '__main__':
    solve()