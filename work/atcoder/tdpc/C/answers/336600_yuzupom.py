K = int(input())
player = 2**K
R = []
winrates = [[0 for i in range(player)] for j in range(player)]
for i in range(player):
    R.append(int(input()))

for i in range(player):
    for j in range(i+1, player):
        winrates[i][j] = 1/(1+pow(10, (R[j]-R[i])/400))
        winrates[j][i] = 1/(1+pow(10, (R[i]-R[j])/400))

rates = [[0 if i > 0 else 1 for j in range(player) ] for i in range(K+1)]
group = 2
match = int(player/2)
for k in range(1, K+1):
    for i in range(match):
        half_group = int(group/2)
        A_min,A_max = group*i, group*i + half_group
        B_min,B_max = group*i + half_group, group*(i+1)
        for j in range(A_min, A_max):
            rates[k][j] = rates[k-1][j] * sum([rates[k-1][b]*winrates[j][b] for b in range(B_min, B_max)])
        for j in range(B_min, B_max):
            rates[k][j] = rates[k-1][j] * sum([rates[k-1][a]*winrates[j][a] for a in range(A_min, A_max)])
    group *= 2
    match = int(match / 2)

for r in rates[K]:
    print("%.10f" % r)