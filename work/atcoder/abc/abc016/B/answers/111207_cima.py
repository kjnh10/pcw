a,b,c=map(int,input().split())
d='!'
if a+b==c:d='+'
if a-b==c:d='-'
if a+b==c and a-b==c:d='?'
print(d)