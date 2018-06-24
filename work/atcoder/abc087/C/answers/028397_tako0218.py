n = int(input())
lis1 = list(map(int,input().split()))
lis2 = list(map(int,input().split()))
ans = []
for i in range(n):
    a = lis1[0:i+1] + lis2[i:]
    ans.append(sum(a))
print(max(ans))