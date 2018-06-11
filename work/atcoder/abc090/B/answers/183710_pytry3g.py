A, B = map(int, input().split())
print(sum(1 for x in range(A, B+1) if str(x) == str(x)[::-1]))   