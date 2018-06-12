N=int(input())
A=[int(i) for i in input().split()]

count=0
success=True
while(success==True):
    for i in range(N):
        if A[i]%2==1:
            success=False
            break
        else:
            A[i]=int(A[i]/2)
    if success==False:
        break
    count+=1
print(count)
