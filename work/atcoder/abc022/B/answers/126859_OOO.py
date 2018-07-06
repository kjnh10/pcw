N = int(input())
A = list()
for i in range(0, N):
    A.append(int(input()))

cnt = len(A) - len(set(A))

print(cnt)