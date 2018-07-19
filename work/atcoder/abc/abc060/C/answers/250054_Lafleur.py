A = list(map(int,input().split(" ")))
B = list(map(int,input().split(" ")))
C = A[1]
for i in range(A[0]-1):
    ii = i + 1
    if B[ii] - B[i] < A[1]:
        C = C + B[ii] - B[i]
    else:
        C = C +A[1]
print(C)