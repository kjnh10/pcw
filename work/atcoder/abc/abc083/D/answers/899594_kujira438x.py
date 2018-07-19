# -*- coding: utf-8 -*-        

s = input()
l = []
r = []
len_s = len(s)
if(len_s==1):
    print(1)
else:
    for i in range(len_s-1):
        if(s[i]!=s[i+1]):
            l.append(i+1)
            r.append(len_s-i-1)
    if(len(l)==0):
        print(len_s)
    else:
        half = len(l)
        l.extend(r)
        l.sort()
        print(len_s-l[half-1])