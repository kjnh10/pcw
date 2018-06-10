n = int(input())
k = int(input())
x = int(input())
y = int(input())

sum = 0
for i in range(1,n+1):
    if i > k:
        sum += y
    else:
        sum += x

print(sum)