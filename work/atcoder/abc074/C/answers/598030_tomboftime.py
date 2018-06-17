a, b, c, d, e, f = list(map(int, input().split()))

# a,bの組み合わせで作れる水の量を全て計算する
water = set([])
sugar = set([])
max_all = f / 100
a_count = int(max_all // a)

# a, bで作られる全ての水
for i in range(a_count + 1):
    # i*aが存在
    j = 0
    while(True):
        if i == 0 and j == 0:
            j += 1
        if i*a + j*b <= max_all:
            water.add(i*a + j*b)
        else:
            break
        j += 1

c_count = int(f // c)

for i in range(c_count + 1):
    j = 0
    while(True):
        if i*c + j*d <= f:
            sugar.add(i*c + j*d)
        else:
            break
        j += 1

all_water = 0
all_sugar = 0
percent = 0

for i in water:
    for j in sugar:
        if j / (i*100 + j) <= e / (100 + e) and 100*i + j <= f:
            if percent <= j / (i*100 + j):
                all_water = (i*100 + j)
                all_sugar = j
                percent = j / (i*100 + j)

print(all_water, all_sugar)
