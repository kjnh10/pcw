import collections

def solve():
    n = int(input())
    a = [int(x) for x in input().split()]
    ac = dict(collections.Counter(a))

    if n % 2 == 0:
        if 0 in ac:
            return 0
    else:
        if 0 not in ac or ac[0] != 1:
            return 0
        else:
            del ac[0]
    ans = 1

    for k, v in ac.items():
        if (k + n) % 2 == 1 and v == 2:
            ans = (ans * 2) % 1000000007
        else:
            return 0

    return ans

print(solve())
