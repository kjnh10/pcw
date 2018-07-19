n = int(input())

alpha = 'abcdefghijklmnopqrstuvwxyz'

counts = dict()
for l in alpha:
    counts[l] = 50
    
for i in range(n):
    S = input()
    for l in alpha:
        counts[l] = min(counts[l], S.count(l))

res = ""
for l in alpha:
    for _ in range(counts[l]):
        res = res + l
print(res)