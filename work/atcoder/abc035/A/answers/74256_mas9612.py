# coding: utf-8

w, h = map(int, input().split())

if h == w / 4 * 3:
    print('4:3')
else:
    print('16:9')