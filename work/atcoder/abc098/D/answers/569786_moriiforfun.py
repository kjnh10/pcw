n = int(input())
a = list(map(int,input().split()))
state = 0

f = []
for i in range(n):
    f.append(0)
f[0]=1

state = state ^ a[0]

left = 0
for j in range(1,n):
    s = f[j-1]
    while state + a[j] != state ^ a[j]:
        s = s - 1
        state = state - a[left]
        left = left + 1
    f[j] = s + 1
    state = state + a[j]

ans = sum(f)
print(ans)