N=int(input())
A=list(map(int,input().split()))
Y=sum(A) // N
Sol=10**9
for y in range(Y-2,Y+2):
    Sol=min(Sol,sum(((a-y)**2 for a in A)))
print(Sol)