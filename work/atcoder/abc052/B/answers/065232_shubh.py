x = 0
m = 0
n = int(input())
s = list(input())
for i in s:
    if i == 'I':
        x += 1
    if i == 'D':
        x -= 1
    m = max(x,m)

print(m)