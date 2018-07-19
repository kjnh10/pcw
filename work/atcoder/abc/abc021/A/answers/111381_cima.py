n=int(input())
for x in [1,2,4]:
    if x==n:
        print(1,x,sep='\n');exit()
    for y in [2,4,8]:
        if x+y==n:print(2,x,y,sep='\n');exit()
print(4,1,1,1,4,sep='\n')