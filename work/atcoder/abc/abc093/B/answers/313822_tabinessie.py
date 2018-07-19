a, b, k = map(int, input().split(' '))

tmp = []
for i in range(k):
    if a + i <= b:
        tmp.append(a + i)
    if b - i >= a:
        tmp.append(b - i)
    
for i in sorted(set(tmp)):
    print(i)