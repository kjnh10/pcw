# 4-adjacent
N = int(input())
a = list(map(int, input().split()))

b = [a[i]%4 for i in range(N)]

if ( b.count(2)%2 + b.count(1) + b.count(3) > 1 + b.count(0) ):
    print("No")
else:
    print("Yes")