n=int(input())
a=list(map(int,input().split()))
dic={}
for n in a:
    if n in dic:
        dic[n]+=1
    else:
        dic[n]=1
ans=0
for k in dic.keys():
    if dic[k]-k>0:
        ans+=dic[k]-k
    elif dic[k]-k==0:
        pass
    else:
        ans+=dic[k]
print(ans)
        
        