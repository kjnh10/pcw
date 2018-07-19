import itertools

s = list(input())
n = int(input())

l = list(itertools.product(s, s))[n - 1]
print(l[0] + l[1])