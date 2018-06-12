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

    ans = 0
    for t in range(N):
        if t == 0 or t == N - 1 or h_list[t - 1] < h_list[t] > h_list[t + 1]:
            s, u = t, t
            for i in range(t, -1, -1):
                s = i
                if i - 1 >= 0 and h_list[i - 1] > h_list[i]:
                    break
            for i in range(t, N):
                u = i
                if i + 1 < N and h_list[i] < h_list[i + 1]:
                    break

            ans = max(ans, u - s + 1)

    print(ans)


if __name__ == '__main__':
    main()
