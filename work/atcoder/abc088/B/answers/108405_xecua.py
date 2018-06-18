f = lambda :[int(i) for i in input().split()]

N = int(input())
a = f()

a.sort()
alice = 0
bob = 0
while a:
    alice += a.pop()
    if not(a):
        break
    bob += a.pop()
print(alice - bob)