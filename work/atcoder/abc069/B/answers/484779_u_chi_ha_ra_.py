s = input()

ans = s[0]
ans += str(len(s) - 2)
ans += s[len(s) - 1]

print(ans)
