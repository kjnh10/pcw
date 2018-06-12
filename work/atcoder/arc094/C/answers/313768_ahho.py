a,b,c = sorted(map(int,input().split()))

cost = 0
cost += (b-a)//2
a += cost*2
if a < b:
  c += 1
  a += 1
  cost += 1

cost += c-b
print(cost)