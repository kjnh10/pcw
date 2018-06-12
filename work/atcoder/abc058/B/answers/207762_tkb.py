a = input()
b = input()
p = ""
for i in range(len(a)):
    p += a[i]
    if len(b)>i:
        p+=b[i]
        
print(p)