input()
a=sorted(int(x)for x in input().split())
m=a[-1]
print(m,min(a,key=lambda x:abs(m-x*2)))