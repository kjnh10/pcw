n = int(input())
flower = set()
count = 0

for i in range(n):
    a = int(input())
    if a in flower:
        count += 1
    flower.add(a)

print(count)