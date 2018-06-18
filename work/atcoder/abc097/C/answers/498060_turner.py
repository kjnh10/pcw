s = list(input())
k = int(input())
l = []
for i in range(1, k+1):
  for j in range(0, len(s)-i+1):
    l.append("".join(s[j:j+i]))

l = sorted(set(l))

print(l[k-1])