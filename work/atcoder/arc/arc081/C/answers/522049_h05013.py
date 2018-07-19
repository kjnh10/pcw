from collections import Counter
n = int(input())
C = Counter(map(int,input().split()))
quad = [i for i in C if C[i] >= 4]
if quad: maxa = max(quad)**2
else: maxa = 0

twice = [i for i in C if C[i] >= 2]
twice.sort()
if len(twice) >= 2: maxa = max(maxa, twice[-1]*twice[-2])
print(maxa)