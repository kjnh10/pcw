#!/usr/bin/env python


def main():
    N, K = map(int, input().split())
    rate = [int(i) for i in input().split()]
    rate.sort()
    rate = rate[N - K:]
    my_rate = 0
    for i in range(len(rate)):
        my_rate = (my_rate + rate[i]) / 2
    print(my_rate)

if __name__ == '__main__':
    main()
