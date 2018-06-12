n = input()
xs = [int(c) for c in input().split()]

p = xs[::2]
q = xs[1::2]

if len(xs) & 1:
    a = list(reversed(p)) + q
else:
    a = list(reversed(q)) + p

print(' '.join(map(str, a)))