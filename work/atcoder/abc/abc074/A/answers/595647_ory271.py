# coding: utf-8
def get_ln_inputs():
    return input().split()


def get_ln_int_inputs():
    return list(map(int, get_ln_inputs()))


def main():
    N = get_ln_int_inputs()[0]
    A = get_ln_int_inputs()[0]
    print(N * N - A)
    return


main()