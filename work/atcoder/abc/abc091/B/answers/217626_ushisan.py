n = int(input())
s = []
for i in range(n):
    s.append(input())

m = int(input())
t = []
for i in range(m):
    t.append(input())
sset = set(s)
money = 0
for i in sset:
    money = max(money,s.count(i)-t.count(i))
print(money)