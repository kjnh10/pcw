import sys,collections
sys.setrecursionlimit(10**7)
def Is(): return [int(x) for x in sys.stdin.readline().split()]
def Ss(): return sys.stdin.readline().split()
def I(): return int(sys.stdin.readline())
def S(): return input()

x,y = Ss()

x = int(x,16)
y = int(y,16)

if x > y:
    print(">")
elif x < y:
    print("<")
else:
    print("=")

