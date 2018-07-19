def solve(s, k):
    can = set()

    for l in range(k):
        for i in range(len(s) - l):
            can.add(s[i:i + l + 1])
    can.discard('')
    can = sorted(can)
    return can[k-1]


s = input()
k = int(input())
print(solve(s, k))
