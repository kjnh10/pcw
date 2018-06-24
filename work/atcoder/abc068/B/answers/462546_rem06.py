num = int(input())
cnt =0
while num>1:
    num = int(num/2)
    cnt +=1
print(2**cnt)