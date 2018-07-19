n, a, b = map(int, input().split())
ans = 0

for i in range(n):
    s, d = input().split()
    d = int(d)

    move = 0
    if d < a:
        move = a
    elif a <= d <= b:
        move = d
    elif b < d:
        move = b

    if s == "West":
        move *= -1
    else:
        pass

    ans += move

out = str()
if ans > 0:
    out = "East {0}".format(abs(ans))
elif ans < 0:
    out = "West {0}".format(abs(ans))
else:
    out = 0
print(out)
