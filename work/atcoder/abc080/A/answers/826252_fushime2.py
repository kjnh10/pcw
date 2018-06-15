def read(): return list(map(int, input().split()))

n,a,b=read()
print(min(n*a,b))