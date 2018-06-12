from collections import Counter
N, K = map(int, input().split())
counter = Counter(input().split())
arr = counter.most_common()
print(sum(map(lambda x:x[1], arr[K:])))