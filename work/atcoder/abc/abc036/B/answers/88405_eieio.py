n = int(input())
s = []
for i in range(n):
    s.append(input())
for s in zip(*reversed(s)):
    print(''.join(s))