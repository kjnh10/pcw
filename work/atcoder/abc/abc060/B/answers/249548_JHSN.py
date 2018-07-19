a, b, c = map(int, input().split())
aa = a
for i in range(200):
    if a == c:
        print("YES")
        exit(0)
    a = (a + aa) % b
print("NO")
