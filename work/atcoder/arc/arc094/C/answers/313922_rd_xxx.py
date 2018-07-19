arr = list(map(int,input().split()))
a = max(arr)*3 - sum(arr)
if a%2 == 1:
    a += 3
print(a//2)
