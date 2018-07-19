# coding=utf-8

import sys
stdin = sys.stdin
def na(): return map(int, stdin.readline().split())
def ns(): return stdin.readline().strip()

def main():
    sx,sy,tx,ty = na()
    # sx,sy,tx,ty=0,0,1,2
    ret = ""
    for i in range(tx-sx):
        ret += "R"
    for i in range(ty-sy):
        ret += "U"
    for i in range(tx-sx):
        ret += "L"
    for i in range(ty-sy):
        ret += "D"
    ret += "D"
    for i in range(tx-sx+1):
        ret += "R"
    for i in range(ty-sy+1):
        ret +="U"
    ret += "L"
    ret += "U"
    for i in range(tx-sx+1): ret += "L"
    for i in range(ty-sy+1): ret += "D"
    ret += "R"
    print(ret)
    pass


if __name__ == '__main__':
    main()