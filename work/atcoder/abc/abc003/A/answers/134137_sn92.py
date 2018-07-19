#!/usr/bin/env python


def main():
    N = int(input())
    sum = 0
    for i in range(1, N + 1, 1):
        sum += i * 10000
    sulary = sum / N
    print(sulary)

if __name__ == '__main__':
    main()
