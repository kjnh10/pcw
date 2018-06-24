
N = int(input())
a = list(map(int,input().split()))
maxa  = max(a)
mina  = min(a)

print(2*N-1)
r = False
if abs(maxa) >= abs(mina):
    d = maxa
else:
    r = True
    d = mina
ind = a.index(d) + 1

for i in range(N):
    print(ind, i+1)

if r:
    for i in range(N - 1)[::-1]:
        print(i+2, i+1)
else:
    for i in range(N-1):
        print(i+1, i+2)