L, X, Y, S, D = map(int, input().split())
ans = ((D - S + L) % L) / (X + Y)
if Y - X > 0:
    ans = min(ans, ((S - D + L) % L) / (Y - X))
print(ans)
