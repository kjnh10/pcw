N = int(input())
prev = False
cnt = 0
plist = list(map(int,input().split()))
for i in range(len(plist)):
  p = plist[i]
  if i+1 == p:
    if prev == False:
      cnt += 1
      prev = True
    else:
      prev = False
  else:
    prev = False
print(cnt)