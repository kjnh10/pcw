import re
n = int(input())
s = []
for i in range(n):
    s.append(input())
    
c = "abcdefghijklmnopqrstuvwxyz"
result = ""
for i in range(len(c)):
    thisC = c[i]
    clen = [len(re.sub(r"[^"+thisC+"]", "", s[j])) for j in range(len(s))]
    result += c[i]*min(clen)
print(result)