import numpy as np
input()
a = np.array(tuple(int(n) for n in input().split()))
odds, l = a[a%2>0], a.size
while a.size:
    a = a[a%2==0] // 2
    odds = np.concatenate((odds, a[a%2>0]))
print(np.unique(odds).size)