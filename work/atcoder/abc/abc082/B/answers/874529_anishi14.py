# coding: utf-8
s=list(input())
t=list(input())
if(sorted(s)<sorted(t,reverse=True)):
    print('Yes')
else:
    print('No')