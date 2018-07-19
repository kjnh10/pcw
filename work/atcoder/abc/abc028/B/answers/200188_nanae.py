import sys

def solve():
    s = input()
    cnt = [0] * 6

    for ch in s:
        cnt[ord(ch) - ord('A')] += 1

    print(*cnt)

def debug(x, table):
    for name, val in table.items():
        if x is val:
            print('DEBUG:{} -> {}'.format(name, val), file=sys.stderr)
            return None

if __name__ == '__main__':
    solve()