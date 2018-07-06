import math
input()
a=[]
for x in map(int,input().split()):
    if x!=0:a+=[x]
print(math.ceil(sum(a)/len(a)))