
n = int(input())
a = [-1] + list(map(int, input().split())) + [-1]

r = 0
c = 0
for i in range(1,n+1):
    if a[i-1] < a[i]:
        c += 1
    else:
        c = 1
    r += c

print(r)
