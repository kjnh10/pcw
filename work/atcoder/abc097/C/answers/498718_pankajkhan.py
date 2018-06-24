# cook your dish here
# from math import * 
#for _ in range(int(input().strip())):

s = input()
k = int(input())
var = 0
sub = set()
size = 0
for var in range(97,123):
    if len(sub)>k:
        break
    for i in range(len(s)):
        size=0
        if s[i]==chr(var):
            for j in range(i,len(s)):
                if size>=k:
                    break
                sub.add(s[i:(j+1)])
                size+=1 
l = list(sub)
l.sort()
print(l[k-1])