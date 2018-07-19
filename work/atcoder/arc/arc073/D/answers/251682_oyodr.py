N, W = map(int, input().split())
ws = []
vs = []
for i in range(N):
    w, v = map(int, input().split())
    ws.append(w)
    vs.append(v)

vss = [[], [], [], []]

for i in range(N):
    ind = ws[i] - ws[0]
    vss[ind].append(vs[i])

for i in range(4):
    vss[i].sort(reverse=True)

dic = {}

# select_S: (a, b, c, d)


def rec(vss, tmp_W, tmp_V, select_S):
    # print(select_S)
    for i in range(4):
        if len(vss[i]) == 0:
            continue
        new_tmp_W = tmp_W + ws[0] + i
        if new_tmp_W > W:
            continue
        new_tmp_V = tmp_V + vss[i][0]
        new_vss = list(vss)
        new_vss[i] = new_vss[i][1:]

        new_select_S = [select_S[j] for j in range(4)]
        new_select_S[i] += 1
        new_select_S = tuple(new_select_S)
        if new_select_S in dic:
            continue

        dic[new_select_S] = new_tmp_V
        rec(new_vss, new_tmp_W, new_tmp_V, new_select_S)


rec(vss, 0, 0, (0, 0, 0, 0))
ans = sorted(list(dic.values()), reverse=True)
if len(ans) == 0:
    print(0)
else:
    print(ans[0])
