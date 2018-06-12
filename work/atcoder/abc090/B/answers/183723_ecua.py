f = lambda :[int(i) for i in input().split()]

A,B = f()
ans = 0

for i in range(A,B+1):
    po = str(i)
    if po[0]==po[4] and po[1] == po[3]:
        ans += 1
        
print(ans)