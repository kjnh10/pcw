[a,b]=[int(i) for i in input().split()]
c=abs(b-a)%10
d=int(abs(b-a)/10)
e=[0,1,2,3,2,1,2,3,3,2]
print(d+e[c])