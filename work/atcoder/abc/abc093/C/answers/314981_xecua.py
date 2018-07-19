f = lambda :[int(i) for i in input().split()]
from sys import stderr
debug = lambda x:stderr.write(repr(x)+'\n')

a,b,c = sorted(f())
ans = 0
while a < b:
    a += 2
    ans += 1
if b < a:
    b += 1
    c += 1
    ans += 1
while b < c:
    a += 1
    b += 1
    ans += 1
print(ans)