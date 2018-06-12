import itertools
S = input()
group = list(itertools.groupby(S))
print(len(group) - 1)
