n = int(input())
s = input()

v = "b"
ans = -1

for i in range(1, n+1):
    if s == "b":
        ans = 0
        break
    
    if i % 3 == 1:
        v = "a" + v + "c"
    if i % 3 == 2:
        v = "c" + v + "a"
    if i % 3 == 0:
        v = "b" + v + "b"

    if v == s:
        ans = i
        break

print(ans)
