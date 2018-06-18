A, B, C, X, Y = map(int, input().split())
if A+B>C*2:
    ans = 2*C*min(X, Y)
    if X>Y:
        ans += (X-Y)*min(A, 2*C)
    elif X<Y:
        ans += (Y-X)*min(B, 2*C)
else:
    ans = X*A+Y*B
print(ans)