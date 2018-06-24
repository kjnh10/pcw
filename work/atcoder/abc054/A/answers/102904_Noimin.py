a,b = list(map(int, input().split(' ')))
if a == 1:
    a = 20
if b == 1:
    b = 20

if a == b:
    print("Draw")
elif a > b:
    print("Alice")
else:
    print("Bob")