def f(n,s):
  if n == 0:
    print(s)
    return
  f(n-1,s+'a')
  f(n-1,s+'b')
  f(n-1,s+'c')
f(int(input()),'')
