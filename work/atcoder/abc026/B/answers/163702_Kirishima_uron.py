PI = 3.14159265359
N = input()
a=[]
ans = 0

for i in range(int(N)):
    a.append(int(input()))    
f = True
a.sort()
a.reverse()
for i in range(int(N)):
    a[i] = int(a[i])
    if f:
      ans += a[i]*a[i]*PI
      f = False
    else:
      ans -= a[i]*a[i]*PI
      f = True

print(ans)