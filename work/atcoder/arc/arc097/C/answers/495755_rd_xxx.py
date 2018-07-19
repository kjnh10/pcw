S = input()
N = len(S)
K = int(input())

subs = set()
for i in range(N):
    for k in range(K):
        subs.add(S[i:i+1+k])
print(sorted(subs)[K-1])
