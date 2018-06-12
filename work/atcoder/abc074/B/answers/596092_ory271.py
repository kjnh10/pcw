# coding: utf-8
def get_ln_inputs():
    return input().split()


def get_ln_int_inputs():
    return list(map(int, get_ln_inputs()))


def main():
    N = get_ln_int_inputs()[0]
    K = get_ln_int_inputs()[0]
    xs = get_ln_int_inputs()

    ans = 0
    for x in xs:
        ans += min(abs(K - x), abs(x))

    print(2 * ans)
    return


main()