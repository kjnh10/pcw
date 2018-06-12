# coding: utf-8

A, B, C, X, Y = [int(x) for x in input().split()]

p1 = X * A + Y * B
m = min(X, Y)
p2 = m * 2 * C + (X - m) * A + (Y - m) * B
M = max(X, Y)
p3 = M * 2 * C

print(min(p1, p2, p3))