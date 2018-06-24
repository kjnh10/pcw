N = int(input())
A = list(map(int, input().split()))

All = abs(A[0]) + abs(A[-1])
for i in range(len(A)-1):
    All += abs(A[i+1] - A[i])

print(All - ( abs(A[0]) + abs(A[1]-A[0])) + abs(A[1]))
for i in range(1, len(A)-1):
    print(All- (abs(A[i+1]-A[i]) + abs(A[i-1] - A[i])) + abs(A[i+1]-A[i-1]))

print(All - (abs(A[-1])+abs(A[-1]-A[-2])) + abs(A[-2]))
