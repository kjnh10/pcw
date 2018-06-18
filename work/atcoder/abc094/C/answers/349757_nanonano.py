N = int(input())
xs = list(map(int,input().split()))
sortxs = [i for i in xs]
sortxs.sort()
mins = sortxs[N//2-1]
majs = sortxs[N//2]
for i in range(N):
    t = xs[i]
    if t <= mins:
        print(majs)
    else:
        print(mins)
