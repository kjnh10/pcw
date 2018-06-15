N = int(input())
S = [input(), input()]
MOD = 1000000007

i = 0
ans = 3
prev_n = 0
while i < N:
    if S[0][i] == S[1][i]:
        n = 1
        i += 1
    else:
        n = 2
        i += 2
    if prev_n == 0 and n == 2:
        ans *= 2
    elif prev_n == 1:
        ans = (ans * 2) % MOD
    elif prev_n == 2 and n == 2:
        ans = (ans * 3) % MOD
    prev_n = n
print(ans)
