MOD = 1000000007


def solve(n, s1, s2, allowed):
    if n == 0:
        return 1

    if s1[0] == s2[0]:
        return (allowed * solve(n - 1, s1[1:], s2[1:], 2)) % MOD
    else:
        if allowed == 3:
            mul = 6
        elif allowed == 2:
            mul = 2
        else:
            mul = 3
        return (mul * solve(n - 2, s1[2:], s2[2:], 1)) % MOD


def main():
    n = int(input())
    s1, s2 = input(), input()
    print(solve(n, s1, s2, 3))

if __name__ == '__main__':
    main()
