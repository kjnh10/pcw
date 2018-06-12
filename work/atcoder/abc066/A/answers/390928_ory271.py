# coding: utf-8
def get_ln_inputs():
    return input().split()


def get_ln_int_inputs():
    return list(map(int, get_ln_inputs()))


def main():
    p = get_ln_int_inputs()
    print(sum(p) - max(p))


main()