from collections import defaultdict
from itertools import product, combinations
import bisect


def main():
    S = input()
    a = []
    num_of_plus, num_of_minus = 0, 0
    for i in range(len(S) - 1, -1, -1):
        num_of_plus += S[i] == "+"
        num_of_minus += S[i] == "-"
        if S[i] == "M":
            a.append(num_of_plus - num_of_minus)

    a.sort()
    print(-sum(a[:len(a)//2]) + sum(a[len(a)//2:]))


if __name__ == '__main__':
    main()
