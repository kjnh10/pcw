n,T = map(int, input().split(' '))
t = list(map(int, input().split(' ')))

dift = [t[i]-t[i-1] for i in range(1,n)]
ret = [min(dift_,T) for dift_ in dift]

print(sum(ret)+T)