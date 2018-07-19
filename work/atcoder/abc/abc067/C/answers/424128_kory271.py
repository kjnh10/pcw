# coding: utf-8
def get_ln_inputs():
    return input().split()


def get_ln_int_inputs():
    return list(map(int, get_ln_inputs()))


def is_closer(s, orig, insp):
    return abs(s - orig * 2) > abs(s - insp * 2)

def main():
    N = get_ln_int_inputs()[0]
    a = get_ln_int_inputs()

    s = sum(a)

    minimum_v = a[0]
    p_s = minimum_v
    for i in range(1, N - 2):
        p_s += a[i]
        if is_closer(s, minimum_v, p_s):
            minimum_v = p_s

    print(abs(s - minimum_v * 2))


main()