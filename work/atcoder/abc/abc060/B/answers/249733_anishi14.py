a,b,c=map(int,input().split())
i=1
memo=[]
while True:
    if (a*i)%b not in memo:
        memo.append((a*i)%b)
    else:
        break
    i+=1
if c in memo:
    print('YES')
else:
    print('NO')
