a,b = map(int, input().split())
n = b - a
snow = n*(n+1)//2
print(snow-b)