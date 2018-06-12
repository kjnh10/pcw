s=input()
x,y=map(int,input().split())
dpx=set()
dpy=set()
xs=[]
ys=[]
tmp=0
d=0
for c in s:
    if c=='F':
        tmp+=1
    elif c=='T':
        if tmp:
            if d==0:
                xs.append(tmp)
            else:
                ys.append(tmp)
        d^=1
        tmp=0
if tmp:
    if d==0:
        xs.append(tmp)
    else:
        ys.append(tmp)
if s[0]=='F':
    dpx.add(xs[0])
    xs=xs[1:]
else:
    dpx.add(0)
dpy.add(0)
for a in xs:
    tmp=set()
    for dx in dpx:
        tmp.add(dx+a)
        tmp.add(dx-a)
    dpx=tmp
for a in ys:
    tmp=set()
    for dy in dpy:
        tmp.add(dy+a)
        tmp.add(dy-a)
    dpy=tmp

#print(dpx,dpy)
if x in dpx and y in dpy:
  print("Yes")
else:
  print("No")
