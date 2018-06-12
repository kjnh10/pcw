N, K = list(map(int, input().split()))
D = input().split()

while True:
    ok = True
    for d in D:
        if str(N).find(d) >= 0:
            ok = False
            break
    if ok:
        print(N)
        break
    N += 1