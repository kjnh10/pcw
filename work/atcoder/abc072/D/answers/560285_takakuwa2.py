N = int(input())
p= list(map(int,input().split()))
ans =0
for i in range(len(p)):
    if not p[i]== i+1:
        continue
    if i+1 <N and p[i]!= i+2 or i==0:
        tmp = p[i]
        p[i] =p[i+1]
        p[i+1]=tmp
        ans+=1
    else:
        tmp=p[i]
        p[i]=p[i-1]
        p[i-1]=tmp
        ans +=1
    #print(p)

print(ans)