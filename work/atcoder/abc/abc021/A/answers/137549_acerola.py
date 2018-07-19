

a=int(input())
x=format(a,"b")
sum=0
z=[]
for i in range(0,len(x)):
    if x[i]=='1':
        z.append(2**(len(x)-i-1))
        sum+=1
print(sum)
for q in z:
    print(q)