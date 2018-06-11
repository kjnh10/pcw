# coding: utf-8
def get_ln_inputs():
    return input().split()


def get_ln_int_inputs():
    return list(map(int, get_ln_inputs()))


def main():
    N, K = get_ln_int_inputs()
    l = get_ln_int_inputs()

    print(sum(sorted(l)[::-1][:K]))


main()