n = int(input())
s = []
for i in range(n):
    s.append(int(input()))
total = sum(s)
if total % 10 == 0:
    s.sort()
    for i in s:
        if i % 10 != 0:
            total -= i
            break
if total % 10 == 0:
    total = 0
print(total)
