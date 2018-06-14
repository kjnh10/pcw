import math
x=[list(map(int,input().split()))for i in range(int(input()))]
print(max(math.hypot(i[0]-j[0],i[1]-j[1]) for i in x for j in x))