from collections import Counter
l = int(input())
data = input().split()
counter = Counter(data)
s = l - len(counter)
if s % 2 == 0:
    print(len(counter))
else:
    print(len(counter) - 1)