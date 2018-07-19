N = int(input())
a = list(map(int,input().split()))
a.sort()
n = a[-1]
k = n/2
#n/2までの距離の最小
for i in range(N-1):
  r = n/2 - a[i]
  if abs(r) < abs(k): k = r
#print(k,n)
print(n,int(n/2-k))