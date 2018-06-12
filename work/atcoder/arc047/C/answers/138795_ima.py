_,l=map(int,input().split());c=1;s=0
for x in input():
    c+=1if x=='+'else -1
    if c>l:s+=1;c=1
print(s)