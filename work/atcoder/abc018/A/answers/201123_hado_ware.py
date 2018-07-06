a = int(input())
b = int(input())
c = int(input())
n = 0

lst = [a, b, c]
lst.sort()
for count in range(3):
    if lst[n] == a:
        a = str(3-n)
    elif lst[n] == b:
        b = str(3-n)
    elif lst[n] == c:
        c = str(3-n)
    n += 1
print(a+"\n"+b+"\n"+c)