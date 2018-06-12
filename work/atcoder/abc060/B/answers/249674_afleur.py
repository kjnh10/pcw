A = list(map(int,input().split(" ")))
B = 0
for i in range(100):
    if (A[0]*(i + 1)) % A[1] == A[2]:
        B = 1
        break
if B == 1:
    print("YES")
else:
    print("NO") 