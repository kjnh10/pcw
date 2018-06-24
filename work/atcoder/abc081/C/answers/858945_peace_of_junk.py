from collections import Counter

N, K = map(int, input().split())
A = map(int, input().split())
C = Counter(A)
if len(C.keys()) <= K:
    print(0)
else:
    n = len(C.keys()) - K
    print(sum(map(lambda x:x[1],C.most_common()[-n:])))