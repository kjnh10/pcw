# coding: utf-8
def get_ln_inputs():
    return input().split()


def get_ln_int_inputs():
    return list(map(int, get_ln_inputs()))


def main():
    A, B = get_ln_int_inputs()
    C = A + B
    if A % 3 == 0 or B % 3 == 0 or C % 3 == 0:
        print("Possible")
    else:
        print("Impossible")


main()