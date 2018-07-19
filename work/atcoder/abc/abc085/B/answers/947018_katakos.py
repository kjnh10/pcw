from collections import Counter

n = int(input())
c = Counter(int(input()) for _ in range(n))
print(len(c))
