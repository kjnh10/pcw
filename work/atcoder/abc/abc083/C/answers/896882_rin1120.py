X, Y = map(int, input().split())
i = 1
while X*(2**i) <= Y:
  i+=1
print(i)