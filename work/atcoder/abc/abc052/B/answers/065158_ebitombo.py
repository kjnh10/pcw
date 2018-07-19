n = int(input())
s = input()

mx = 0
x = 0
for c in s:
    if c == 'I':
        x += 1
        if x > mx:
            mx = x
    else:
        x -= 1

print(mx)
