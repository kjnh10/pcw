#!/usr/bin/env python3

import array


class CumulativeSum(object):

    def __init__(self, sequence, typecode="L"):
        self.cumulative_sum = array.array(typecode)
        self.cumulative_sum.append(0)
        for element in sequence:
            self.cumulative_sum.append(self.cumulative_sum[-1] + element)

    def partial_sum(self, first, last):
        return self.cumulative_sum[last + 1] - self.cumulative_sum[first]


def compute_sum(n, k, xs):
    cs = CumulativeSum(xs)
    answer = 0
    for start_idx in range(n - k + 1):
        answer += cs.partial_sum(start_idx, start_idx + k - 1)
    return answer


def main():
    n, k = map(int, input().split())
    xs = array.array("L", map(int, input().split()))
    print(compute_sum(n, k, xs))


if __name__ == '__main__':
    main()
