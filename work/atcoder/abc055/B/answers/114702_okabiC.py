N = int(input())
Ans = 1
for i in range(1,N+1):
    Ans = (Ans*i)%1000000007

print(Ans)