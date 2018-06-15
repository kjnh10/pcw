n = int(input())
a = list(map(int, input().split()))
a.sort()
a.reverse()

l = 0
ans = []
for i in a:
    if l == i:
        ans.append(i)
        l = 0
    else:
        l = i
    if len(ans) == 2:
        print(ans[0] * ans[1])
        exit()
print(0)
      