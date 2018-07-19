N, K = map(int,input().split())
D = list(map(str, input().split()))

while True:
    S = str(N)
    t = 0
    for x in S:
        if x not in D:
            t += 1
    if t == len(S):
        print(S)
        break
    else:
        N += 1
