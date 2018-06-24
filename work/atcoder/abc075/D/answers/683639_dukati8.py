line=input().split()
n=int(line[0])
k=int(line[1])

points=[]
hojds=[]
bredds=[]
for i in range(n):
    line=input().split()
    x=int(line[0])
    y=int(line[1])
    points.append([x,y])
    bredds.append(x)
    hojds.append(y)
hojds.sort()
bredds.sort()
points.sort(key=lambda x:x[0])

area=10**18*4
for h1 in hojds:
    for h2 in hojds:
        if h1>=h2:
            continue
        for b1 in bredds:
            num=0
            for p in points:
                if p[0]>=b1 and p[1]>=h1 and p[1]<=h2:
                    num+=1
                    if num==k:
                        b2=p[0]
                        newarea=(b2-b1)*(h2-h1)
                        area=min(area,newarea)
                        break
            
print(area)
