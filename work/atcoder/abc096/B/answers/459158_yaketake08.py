A = sorted(map(int, input().split()))
print(sum(A[:2]) + A[-1]*2**int(input()))