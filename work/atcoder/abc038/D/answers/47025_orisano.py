from bisect import *
import sys


def LIS(seq):
    INF = max(seq) + 1
    N = len(seq)
    lis = [INF] * (N + 1)
    for x in seq:
        lis[bisect_left(lis, x)] = x
    return lis[:bisect_left(lis,INF)]

def main():
    N = int(input())
    P = [tuple([int(x, 10) for x in line.split(" ")]) for line in sys.stdin.readlines()]
    print(len(LIS([x for _, x in sorted(P, key=lambda p: (p[0], -p[1]))])))

if __name__ == "__main__":
    main()
