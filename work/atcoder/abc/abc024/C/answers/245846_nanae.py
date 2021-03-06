import sys

def solve():
    n, d, k = map(int, sys.stdin.readline().split())
    lr = [[int(i) for i in sys.stdin.readline().split()] for j in range(d)]

    for i in range(k):
        s, t = map(int, sys.stdin.readline().split())

        if t < s:
            flag = -1
        else:
            flag = 1

        for i, (l, r) in enumerate(lr):
            if flag == -1:
                if l <= t <= s <= r:
                    print(i + 1)
                    break
                elif t < l <= s <= r:
                    s = l
            else:
                if l <= s <= t <= r:
                    print(i + 1)
                    break
                elif l <= s <= r < t:
                    s = r


if __name__ == '__main__':
    solve()