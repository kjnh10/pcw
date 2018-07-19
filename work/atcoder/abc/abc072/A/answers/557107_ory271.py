# coding: utf-8
def get_ln_inputs():
    return input().split()


def get_ln_int_inputs():
    return list(map(int, get_ln_inputs()))


def main():
    X, t = get_ln_int_inputs()
    print(max(0, X - t))
    return


main()