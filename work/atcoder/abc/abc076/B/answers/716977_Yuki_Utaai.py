a=int(input())
b=int(input())
num=1

for i in range(a):
    num=min(2*num,num+b)

print(num)

