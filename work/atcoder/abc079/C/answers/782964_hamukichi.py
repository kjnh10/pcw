#!/usr/bin/env python3

import itertools


def find_eq(abcd):
    a, b, c, d = abcd
    ops = ("+", "-")
    for op1, op2, op3 in itertools.product(ops, repeat=3):
        eq = a + op1 + b + op2 + c + op3 + d
        if eval(eq) == 7:
            return eq + "=7"


def main():
    print(find_eq(input()))


if __name__ == '__main__':
    main()
