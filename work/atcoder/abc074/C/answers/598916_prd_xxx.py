A,B,C,D,E,F = map(int, input().split())

ws = set()
i = j = 0
while True:
    j = 0
    if B*i > F//100: break
    while True:
        w = B*i + A*j
        if w > F//100: break
        ws.add(w)
        j += 1
    i += 1
ws = list(ws)
ws.sort()

ss = set()
i = j = 0
while True:
    j = 0
    if D*i > F: break
    while True:
        s = D*i + C*j
        if s > F: break
        ss.add(s)
        j += 1
    i += 1
ss = list(ss)
ss.sort()

limit = E / (100+E)
water = A*100
sugar = rate = 0
for w in ws:
    w = w*100
    if w == 0: continue
    if w > F: break
    for s in ss:
        if w+s > F: break
        r = s / (w+s)
        if r > limit: break
        if r > rate:
            rate = r
            water = w
            sugar = s
print(water+sugar, sugar)
