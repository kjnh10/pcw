import sys
from itertools import combinations

def solve():
    a = [int(i) for i in input().split()]
    nums = []

    for (i, j, k) in combinations(a, 3):
        nums.append(i + j + k)

    nums.sort(reverse=True)

    ans = nums[2]

    print(ans)

def debug(x, table):
    for name, val in table.items():
        if x is val:
            print('DEBUG:{} -> {}'.format(name, val), file=sys.stderr)
            return None

if __name__ == '__main__':
    solve()