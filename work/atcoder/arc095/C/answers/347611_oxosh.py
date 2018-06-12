# C
N = int(input())
X_list = list(map(int, input().split()))
X_list_s = sorted(X_list)
Right = X_list_s[N // 2]
Left = X_list_s[(N // 2) - 1]
for i in range(N):
    if X_list[i] >= Right:
        print(Left)
    else:
        print(Right)