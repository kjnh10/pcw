a, b, c = map(int, input().split())
flag = False
for i in range(1, 100000):
    if (a*i)%b==c:
        flag = True
        break
print("YES" if flag else "NO")