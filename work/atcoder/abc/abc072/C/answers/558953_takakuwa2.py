from collections import  Counter
N =int(input())

a= list(map(int,input().split()))

c = Counter(a)
new_c = Counter(a)
for key,val in c.items():
    new_c[key-1] +=val
    new_c[key+1] += val

print(new_c.most_common()[0][1])
