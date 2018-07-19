#!/usr/bin/env python3

input()
s = input()
balance = 0
left = 0
for c in s:
    if c == '(':
        balance += 1
    elif balance == 0:
        left += 1
    else:
        balance -= 1
right = balance
print('(' * left + s + ')' * right)
