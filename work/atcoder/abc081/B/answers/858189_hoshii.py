N = int(input())
A = list(map(int, input().split()))

ans = 0
while True:
    ok = True
    for i, a in enumerate(A):
        if a % 2 == 0:
            A[i] //= 2
        else:
            ok = False
            break
    if not ok:
        break
    ans += 1

print(ans)    
