#!/usr/bin/env python3
# -*- coding: utf-8 -*-

def func():
    S = input()
    for idx in range(len(S)):
        if idx > 0:
            if S[idx] == S[idx-1]:
                print("{} {}".format(idx, idx+1))
                return
        if idx > 1:
            if S[idx] == S[idx-2]:
                print("{} {}".format(idx-1, idx+1))
                return
    print("-1 -1")

func()    

