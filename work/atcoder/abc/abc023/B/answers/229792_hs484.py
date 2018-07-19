N=int(input())
T=input()
ans=-1
s='b'
if T == s:
  ans = 0
for i in range(1,N):
  if i % 3 == 1:
    s = 'a' + s + 'c'
  if i % 3 == 2:
    s = 'c' + s + 'a'
  if i % 3 == 0:
    s = 'b' + s + 'b'
  if s == T:
    ans = i
    break
print(ans)