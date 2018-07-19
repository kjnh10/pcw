# coding: utf-8
def get_ln_inputs():
    return input().split()


def map_list(fn, xs):
    return list(map(fn, xs))


def get_ln_int_inputs():
    return map_list(int, get_ln_inputs())


def main():
    N = get_ln_int_inputs()[0]
    K = get_ln_int_inputs()[0]

    m = 1
    for _ in range(N):
        if m > K:
            m += K
        else:
            m = m * 2

    print(m)
    return


main()