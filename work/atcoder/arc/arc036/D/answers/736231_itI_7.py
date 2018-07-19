from collections import defaultdict, Counter
from itertools import product, groupby, count, permutations, combinations
from math import pi, sqrt
from collections import deque
from bisect import bisect, bisect_left, bisect_right
INF = float("inf")


def main():
    N = int(input())
    h_list = []
    for _ in range(N):
        h_list.append(int(input()))

    left_down, right_down = [0] * N, [0] * N
    for i in range(N - 1, 0, -1):
        left_down[i] = h_list[i - 1] < h_list[i]
    for i in range(N - 1):
        right_down[i] = h_list[i] > h_list[i + 1]

    left_one, right_one = [0] * N, [0] * N
    for i in range(N - 2, -1, -1):
        if right_down[i] == 0:
            right_one[i] = 0
        else:
            right_one[i] = right_one[i + 1] + right_down[i]
    for i in range(1, N):
        if left_down[i] == 0:
            left_one[i] = 0
        else:
            left_one[i] = left_one[i - 1] + left_down[i]

    ans = 0
    # print(right_down)
    # print(right_one)
    for t in range(N):
        # s, u = t, t
        # for i in range(t, -1, -1):
        #     s = i
        #     if left_down[i] == 0:
        #         break
        # for i in range(t, N):
        #     u = i
        #     if right_down[i] == 0:
        #         break
        s2 = left_one[t]
        u2 = right_one[t]
        # print(t)
        # print(s, t - s2)
        # print(u, t + u2)
        s = t - s2
        u = t + u2
        ans = max(ans, u - s + 1)

    print(ans)


if __name__ == '__main__':
    main()
