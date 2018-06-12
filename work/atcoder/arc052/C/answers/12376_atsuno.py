s=list(input())
a=""
for i in range(len(s)):
    if (s[i] in list(map(str, range(0, 10)))):
        a+=s[i]
print(a)