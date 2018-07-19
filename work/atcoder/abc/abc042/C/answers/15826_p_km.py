N, _ = [int(x) for x in input().split()]
D = set(range(10)) - set([int(x) for x in input().split()])
n = [int(x) for x in list(str(N))]

i = 0
while i < len(n):
    if n[i] not in D:
        cand = {x for x in D if x > n[i]}
        if len(cand) > 0:
            n[i] = min(cand)
            for j in range(i + 1, len(n)):
                n[j] = 0
            i += 1
        elif i > 0:
                n[i - 1] += 1
                n[i] = 0
                i -= 1
        else:
            n = [1] + [0] * len(n)
    else:
        i += 1

print(''.join([str(x) for x in n]))
