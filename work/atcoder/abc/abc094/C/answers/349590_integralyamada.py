N = int(input())
X = list(map(int, input().split()))

Xsort = sorted(X)
medR = Xsort[N//2]
medL = Xsort[N//2-1]

for i in X:
    if i < medR:
        print(medR)
    else:
        print(medL)
