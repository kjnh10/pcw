def inpl(): return list(map(int, input().split()))
A, B, K = inpl()
ans = []
for i in range(K):
    ans.append(A+i)
    ans.append(B-i)
for i in sorted(set(ans)):
    if A <= i and i <= B:
        print(i)