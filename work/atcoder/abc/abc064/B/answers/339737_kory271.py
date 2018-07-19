# coding: utf-8
def get_ln_inputs():
    return input().split()


def get_ln_int_inputs():
    return list(map(int, get_ln_inputs()))


def main():
    _ = get_ln_int_inputs()
    a = get_ln_int_inputs()
    print(max(a) - min(a))


main()