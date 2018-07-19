N = int(input())
S = [int(input()) for _ in range(N)]

sumv = sum(S)
if sumv % 10 != 0:
    print(sumv)
    exit()

S.sort()
for s in S:
    if s % 10 != 0:
        sumv -= s
        print(sumv)
        exit()
print(0)
