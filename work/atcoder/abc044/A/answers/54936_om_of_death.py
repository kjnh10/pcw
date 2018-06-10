import re
import doctest


class IO_for_Contest(object):
    @staticmethod
    def my_input():
        # return raw_input()
        return input()

    @staticmethod
    def read_from_input():
        n = IO_for_Contest.read_int()
        k = IO_for_Contest.read_int()
        x = IO_for_Contest.read_int()
        y = IO_for_Contest.read_int()
        return n, k, x, y

    @staticmethod
    def read_line():
        return IO_for_Contest.my_input().strip()

    @staticmethod
    def read_int():
        return int(IO_for_Contest.my_input().strip())

    @staticmethod
    def read_n_int(n):
        return list(map(
                    int,
                    re.split('\s+', IO_for_Contest.my_input().strip())))[: n]


def solve():
    buf = IO_for_Contest.read_from_input()
    n = buf[0]
    k = buf[1]
    x = buf[2]
    y = buf[3]
    if n <= k:
        print(x * n)
    else:
        rem = n - k
        print(x * k + y * rem)


if __name__ == '__main__':
    # doctest.testmod()
    solve()