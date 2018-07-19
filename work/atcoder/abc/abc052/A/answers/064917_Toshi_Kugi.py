a, b, c, d = map(int, input().split())

first = a*b
second = c*d

if first > second:
  print(first)
elif second > first:
  print(second)
else:
  print(first)