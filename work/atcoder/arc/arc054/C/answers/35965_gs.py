L, X, Y, S, D = map(int, input().split())

if S < D:
    if X < Y:
        print(min((D-S)/(X+Y),(L-D+S)/(Y-X)))
    else:
        print((D-S)/(X+Y))
else:
    if X < Y:
        print(min((L-S+D)/(X+Y),(S-D)/(Y-X)))
    else:
        print((L-S+D)/(X+Y))