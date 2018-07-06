import sys
sys.setrecursionlimit(10**8)

n = int(input())
sub = [[] for i in range(n + 1)]
# sub_pay = [[] for i in range(n + 1)]
for i in range(n - 1):
    b = int(input())
    sub[b].append(i + 1)


def recursion_pay(num):
    _sub = sub[num]
    if not _sub:
        return 1

    subs_pay = []
    for i in _sub:
        subs_pay.append(recursion_pay(i + 1))

    pay = min(subs_pay) + max(subs_pay) + 1
    return pay

print(recursion_pay(1))
