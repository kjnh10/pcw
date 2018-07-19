import itertools

s = input()
n = int(input())

comb = list(itertools.product(s, repeat=2))
print("".join(comb[n - 1]))
