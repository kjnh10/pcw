#!/usr/bin/env python
# -*- coding: utf-8 -*-


import math
def solve():
    x,y = map(int, input().split())
    print(int(math.log2(y/x))+1)


if __name__ == "__main__":# {{{
    solve()
# vim: set foldmethod=marker:}}}
