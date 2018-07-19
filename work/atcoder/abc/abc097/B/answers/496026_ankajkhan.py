x = int(input())
l =[1]

for i in range(2,200):
    if i*i > 1000:
        break
    for j in range(2,100):
        if i**j > 1000:
            break
        l.append(i**j)
l.append(1005)
l.sort()
for i in range(len(l)):
    if l[i]>x:
        print(l[i-1])
        exit(0)