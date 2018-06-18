S = input()
n = len(S)
j = 0
for i in range(1, n):
    if S[i - 1] != S[i]:
        if abs(n - 2 * i) < abs(n - 2 * j):
            j = i
print(max([j, n - j]))