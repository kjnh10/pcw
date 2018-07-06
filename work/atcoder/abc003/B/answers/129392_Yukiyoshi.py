ss = list(input())
ts= list(input())
changeable = list("atcoder")

ans = "You can win"
for s, t in zip(ss, ts):
    if s == t:
        continue
    if s == "@" and t in changeable:
        continue
    if t == "@" and s in changeable:
        continue
    else:
        ans = "You will lose"
        break

print(ans)
