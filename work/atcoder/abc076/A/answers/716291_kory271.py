# coding: utf-8
def get_ln_inputs():
    return input().split()


def map_list(fn, xs):
    return list(map(fn, xs))


def get_ln_int_inputs():
    return map_list(int, get_ln_inputs())


def main():
    R = get_ln_int_inputs()[0]
    G = get_ln_int_inputs()[0]
    print(R + 2* (G - R))
    return


main()