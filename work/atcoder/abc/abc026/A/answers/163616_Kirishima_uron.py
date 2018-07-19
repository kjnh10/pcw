a = input()
max = 0
a = int(a)
for i in range(a) :
    if i*(a-i) > max :
            max = i*(a-i)
print(max)
