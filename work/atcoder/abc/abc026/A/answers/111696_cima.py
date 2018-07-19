a=int(input())
print(max(x*y for x in range(99) for y in range(99) if x+y==a))