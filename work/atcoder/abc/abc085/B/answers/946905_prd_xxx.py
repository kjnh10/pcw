from collections import Counter
N = int(input())
src = [int(input()) for i in range(N)]
ctr = Counter(src)
print(len(ctr.items()))
