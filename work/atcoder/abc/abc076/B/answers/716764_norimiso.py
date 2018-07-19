n = int(input())
p = int(input())
num = 1
for a in range(n):
    if num<=p:
        num = num * 2
    else:
        num = num + p
print(num)