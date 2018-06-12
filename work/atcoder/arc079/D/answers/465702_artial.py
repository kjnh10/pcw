import sys

# sys.stdin = open('d1.in')


def read_int_list():
    return list(map(int, input().split()))


def read_int():
    return int(input())


def read_str_list():
    return input().split()


def read_str():
    return input()


def solve():
    k = read_int()
    n = 50
    q, r = divmod(k, n)
    a = [n - 1 + q] * n
    for i in range(r):
        a[i] += n - r + 1
    for i in range(r, n):
        a[i] += -r
    return n, a


def main():
    n, a = solve()
    print(n)
    print(*a)


if __name__ == '__main__':
    main()
