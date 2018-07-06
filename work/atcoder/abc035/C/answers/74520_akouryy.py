n, q = map(int, input().split())
bw = [0] * (n + 1)

for i in range(q):
    l, r = map(int, input().split())
    bw[l - 1] += 1
    bw[r] -= 1

for i in range(n):
    bw[i] %= 2
    bw[i + 1] += bw[i]

print(''.join(map(str, bw[0 : n])))
