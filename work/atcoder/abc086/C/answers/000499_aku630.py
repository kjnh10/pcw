n = int(input())
pret, prea, preb = 0, 0, 0
flag = True
for i in range(n):
    t, a, b = map(int, input().split())
    if (t - pret) % 2 == abs((a + b) - (prea + preb)) % 2 and t - pret >= abs((a + b) - (prea + preb)):
        pass
    else:
        print("No")
        break

    if i == n - 1:
        print("Yes")
