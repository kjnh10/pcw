# -*- coding: utf-8 -*-

# N,Cを取得
n, c = map(int, input().split())

# x1, v1..xN, vNを取得
xs = []
vs = []
for _i in range(n):
    x, v = map(int, input().split())
    xs.append(x)
    vs.append(v)

r1, r2, l1, l2 = [[], [], [], []]
r_sum, l_sum = [0, 0]
for i in range(n):
    r_sum += vs[i]
    r1.append(r_sum - xs[i])
    r2.append(r_sum - 2 * xs[i])

    i_rev = n - i - 1
    l_sum += vs[i_rev]
    l1.append(l_sum - (c - xs[i_rev]))
    l2.append(l_sum - 2 * (c - xs[i_rev]))

r1_max, r2_max = [0, 0]
l1_max, l2_max = [0, 0]
r1_maxs, r2_maxs = [[0], [0]]
l1_maxs, l2_maxs = [[0], [0]]
for i in range(n):
    r1_max = max(r1_max, r1[i])
    r1_maxs.append(r1_max)
    r2_max = max(r2_max, r2[i])
    r2_maxs.append(r2_max)
    l1_max = max(l1_max, l1[i])
    l1_maxs.append(l1_max)
    l2_max = max(l2_max, l2[i])
    l2_maxs.append(l2_max)

r1_l2_max = 0
l1_r2_max = 0
for i in range(0, n + 1):
    r1_l2_max = max(r1_l2_max, r1_maxs[i] + l2_maxs[n - i])
    l1_r2_max = max(l1_r2_max, l1_maxs[i] + r2_maxs[n - i])

total_max = max(r1_l2_max, l1_r2_max)

# 結果を出力
print("{}".format(total_max))
