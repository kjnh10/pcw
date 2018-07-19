n = int(input())
a = map(int, input().split())

flag = -1
odd = 0
m4 = 0
for i in a:
    if i % 4 == 0:
        m4 += 1
    elif i % 2 == 0:
        flag = 0
    else:
        odd += 1

print('Yes' if m4 >= odd + flag else 'No')
