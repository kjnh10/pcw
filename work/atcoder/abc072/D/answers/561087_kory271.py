# coding: utf-8
def get_ln_inputs():
    return input().split()


def get_ln_int_inputs():
    return list(map(int, get_ln_inputs()))


def main():
    N = get_ln_int_inputs()[0]
    p = get_ln_int_inputs()

    arranged_terms = set()
    for i in range(N):
        if p[i] == i + 1:
            arranged_terms.add(i)

    swaps = 0

    double_arranged = set()
    for arranged_term in arranged_terms:
        if (arranged_term + 1) in arranged_terms and (not (arranged_term - 1) in double_arranged):
            double_arranged.add(arranged_term)
    
    single_arranged = set()
    for arranged_term in arranged_terms:
        if not (arranged_term in double_arranged or (arranged_term - 1) in double_arranged):
            single_arranged.add(arranged_term)

    print(len(double_arranged) + len(single_arranged))

main()