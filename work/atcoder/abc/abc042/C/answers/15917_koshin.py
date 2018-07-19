n,k=map(int,input().split())
d=list(map(str,input().split()))
d=set(d)


for i in range(n,10**7):
    ans=set(str(i))

    for j in ans:
        if j in d:
            break
    else:
        print(i)
        exit()