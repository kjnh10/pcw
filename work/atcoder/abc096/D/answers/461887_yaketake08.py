N = int(input())
ans = []
x = 6
while len(ans) < N:
    for y in range(2, x):
        if x % y == 0:
            break
    else:
        ans.append(x)
    x += 5
print(*ans)
