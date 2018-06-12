from collections import defaultdict
S = input()
dic = defaultdict(int)
for c in S:
    dic[c] += 1
x = 0
y = 0
for v in dic.values():
    x += v // 2
    y += v % 2
print((x//y*2+1) if y != 0 else len(S))
