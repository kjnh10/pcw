C = [list(map(int, input().split())) for i in range(3)]
N = 100
ok = 0
for a1 in range(N+1):
    b1 = C[0][0] - a1
    b2 = C[0][1] - a1
    b3 = C[0][2] - a1
    for a2 in range(N+1):
        if not (b1 == C[1][0] - a2) or not (b2 == C[1][1] - a2) or not (b3 == C[1][2] - a2):
            continue
        for a3 in range(N+1):
            if not (b1 == C[2][0] - a3) or not (b2 == C[2][1] - a3) or not (b3 == C[2][2] - a3):
                continue
            ok = 1
            break
        else:
            continue
        break
    else:
        continue
    break
print("Yes"*ok or "No")
