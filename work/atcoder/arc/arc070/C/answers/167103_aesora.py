# coding: utf-8

x = int(input())

i = 0
while True:
    i += 1
    if (i * (i + 1) / 2) >= x:
        print(i)
        break
