N = int(input())
src = [tuple(map(int,input().split())) for i in range(N-1)]

for i in range(N-1):
    time = 0
    for c,s,f in src[i:]:
        if time <= s:
            time = s+c
        else:
            time += (f-(time-s)) % f + c
    print(time)
print(0)
