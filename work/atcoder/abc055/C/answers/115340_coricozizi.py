n,m = list(map(int, input().split()))

def calc(n,m):
  if n>m//2:
    return m//2
  else:
    tcnt = n
    m = m - 2*n
    return tcnt + m//4

print(calc(n,m))
