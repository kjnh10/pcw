K = int(input())

a = [49 for i in range(50)]

for i in range(50):
    a[i] += K//50
    
for i in range(50):
    mod = K % 50
#     if mod != 0:
    if mod >= i+1:
        a[i] = a[i] + 50 - (mod)
    else:
        a[i] = a[i] - (mod)

print(50)
print(*a)