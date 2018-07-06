from math import pi


n   = int(input())
lst = []
for _ in range(n):
    lst.append(int(input()))


def main(lst):
    ret = 0
    for i, e in enumerate(sorted(lst, reverse=True)):
        if i % 2 == 0:
            ret += e * e * pi
        else:
            ret -= e * e * pi
    return ret


print(main(lst))
