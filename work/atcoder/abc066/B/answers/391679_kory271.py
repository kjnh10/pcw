# coding: utf-8
def get_ln_inputs():
    return input().split()


def get_ln_int_inputs():
    return list(map(int, get_ln_inputs()))


def is_ev_st(s):
    l = len(s)
    if l % 2 == 1:
        return False
    l2 = int(l / 2)
    return s[:l2] == s[l2:]


def main():
    S = get_ln_inputs()[0][:-1]
    while not is_ev_st(S):
        S = S[:-1]
    print(len(S))


main()