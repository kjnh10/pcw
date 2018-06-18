import sys

stdin = sys.stdin
def na(): return map(int, stdin.readline().split())
def ns(): return stdin.readline().strip()

a,b = na()
if  a == 1: a += 13
if b == 1: b += 13
if a > b:
    print("Alice")
elif a < b:
    print("Bob")
else:
    print("Draw")
