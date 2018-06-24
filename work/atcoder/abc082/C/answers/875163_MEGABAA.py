N=int(input())
a=list(map(int,input().split()))
cnt={}
for e in a:
  if e in cnt:
    cnt[e]+=1
  else:
    cnt[e]=1
ans=0
for e in a:
  if cnt[e]==0:
    continue
  else:
    if cnt[e] > e:
      ans+=cnt[e]-e
    elif cnt[e] < e:
      ans+=cnt[e]
    cnt[e]=0
print(ans)
