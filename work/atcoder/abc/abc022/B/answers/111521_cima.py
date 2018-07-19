a={};b=[]
for _ in [0]*int(input()):
    c=int(input())
    if c in a:b+=[c]
    else:a[c]=1
print(len(b))