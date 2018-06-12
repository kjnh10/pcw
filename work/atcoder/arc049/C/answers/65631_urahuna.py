s = input()
li = list(map(int, input().split()))
t = ""
j = 0
for i in range(len(s)):
    if j < 4 and li[j] == i:
        t += "\""
        j += 1
    t += s[i]
if li[-1] == len(s):
    t += "\""
print(t)
