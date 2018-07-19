INF = 10 ** 20
n = int(input())
s = input()

w_cum = [0]
e_cum = [0]

w_acc = 0
e_acc = 0
for i in range(n):
  if s[i] == "W":
    w_acc += 1
  else:
    e_acc += 1
  w_cum.append(w_acc)
  e_cum.append(e_acc)

ans = INF
for i in range(1, n + 1):
  ans = min(ans, w_cum[i - 1] + e_cum[-1] - e_cum[i])

print(ans)