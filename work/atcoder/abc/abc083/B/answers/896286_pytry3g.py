N, A, B = map(int, input().split())
cnt = 0
for i in range(1, N+1):
    if A <= sum(int(x) for x in str(i)) <= B:
        cnt += i
print(cnt)
