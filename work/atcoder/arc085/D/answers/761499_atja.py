import sys
sys.setrecursionlimit(10**4)
n, _, y = map(int, input().split())
a = list(map(int, input().split()))
a = [y] + a

memo = [[-1 for i in range(n + 1)] for j in range(2)]
def sol(i, turn):
    # ovaj drugi ima a[i]
    if memo[turn][i] != -1:
        return memo[turn][i]
    best = abs(a[i] - a[n])
    for j in range(i + 1, n):
        pot = sol(j, 1 - turn)
        if turn == 0:
            best = max(best, pot)
        else:
            best = min(best, pot)
    memo[turn][i] = best
    return best

print(sol(0, 0))