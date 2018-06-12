st = input().split()
a = int(st[0])
b = int(st[2])
if st[1] == '+':
    ret = a + b
else:
    ret = a - b

    
print(ret)