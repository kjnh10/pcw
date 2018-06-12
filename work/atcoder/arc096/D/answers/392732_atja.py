n, o = map(int, input().split())
x, v = [], []
for i in range(n):
    a, b = map(int, input().split())
    x.append(a)
    v.append(b)
c = 0

desno, lijevo, y = [], [], []
dd, ll = [0], [0]

tot = 0
for i in range(n):
    if i > 0:
        dd.append(max(dd[-1], desno[-1]))
    tot += v[i]
    desno.append(tot - x[i])

tot = 0
for i in range(n - 1, -1, -1):
    if i < n - 1:
        ll.append(max(ll[-1], lijevo[-1]))
    tot += v[i]
    lijevo.append(tot - (o - x[i]))
    y.append(o - x[i])

#print(desno, dd)
#print(lijevo, ll)

for i in range(n):
    kd = desno[i] - x[i] + ll[n - i - 1]
            #max([lijevo[j] for j in range(n - i - 1)] + [0])
    kl = lijevo[i] - y[i] + dd[n - i - 1]
            #max([desno[j] for j in range(n - i - 1)] + [0])
    #print(kd, kl)
    c = max(c, kd, kl, desno[i], lijevo[i])

print(c)
