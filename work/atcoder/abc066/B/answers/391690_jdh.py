s = input().strip()
ls = len(s)
for i in range(ls//2-1,0,-1):
  if s[:i] == s[i:2*i]:
    print(2*i)
    break