from collections import defaultdict
from itertools import product
from math import pi


def main():
    R, C, K = map(int, input().split())
    N = int(input())
    r_list = [0] * R
    c_list = [0] * C
    candy_list = []
    for _ in range(N):
        r, c = map(int, input().split())
        r -= 1
        c -= 1
        candy_list.append((r, c))
        r_list[r] += 1
        c_list[c] += 1

    candy_row_num = defaultdict(int)
    for i, r in enumerate(r_list):
        candy_row_num[r] += 1

    ans = 0
    for c in c_list:
        rest = K - c
        ans += candy_row_num[rest]

    for r, c in candy_list:
        num = r_list[r] + c_list[c] - 1
        if num == K:
            ans += 1
        if num == K - 1:
            ans -= 1
    print(ans)


if __name__ == '__main__':
    main()
