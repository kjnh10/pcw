p = float(input())

l = 0
r = min(p,100)

for i in range(100):
    m = r - l
    ml = l + m / 3
    mr = l + 2 * m / 3
    #print(m,l,ml,mr,r)
    if ml + p / (2 ** (ml/1.5)) >= mr +p / (2 ** (mr/1.5)):
        l = ml
    else:
        r = mr

if ml + p / (2 ** (ml/1.5)) <= mr + p / (2 ** (mr/1.5)):
    print(ml + p / (2 ** (ml/1.5)))
else:
    print(mr + p / (2 ** (mr/1.5)))
