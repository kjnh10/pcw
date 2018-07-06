N, K = [int(_) for _ in input().split()]
T = [[int(_) for _ in input().split()] for i in range(N)]

E = K ** N
for e in range(E):
    res = 0
    for n in range(N):
        res ^= T[n][e // K**n % K]
        if res == 0:
            print("Found")
            exit()
else:
    print("Nothing")
