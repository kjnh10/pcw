n = int(input())
a = list(map(int, input().split()))
box = []

for i in a:
    while i % 2 == 0:
        i = i // 2
    box.append(i)

print(len(set(box)))