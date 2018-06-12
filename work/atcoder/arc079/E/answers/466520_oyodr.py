N = int(input())
L = list(map(int, input().split()))


def check(lst):
    for i in range(N):
        if lst[i] >= N:
            return False
    return True

ans = 0
while not check(L):
    cnts = []
    for l in L:
        cnts.append(l // N)
    sum_cnts = sum(cnts)
    ans += sum_cnts
    for i in range(N):
        L[i] = L[i] - cnts[i] * N + sum_cnts - cnts[i]
print(ans)
