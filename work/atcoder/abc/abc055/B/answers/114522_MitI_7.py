from collections import defaultdict


def main():
    N = int(input())
    ans = 1
    for i in range(1, N + 1):
        ans *= i
        ans %= 10 ** 9 + 7
    print(ans % (10 ** 9 + 7))


if __name__ == '__main__':
    main()
