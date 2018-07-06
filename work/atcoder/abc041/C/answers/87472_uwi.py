import sys
stdin = sys.stdin
def na(): return map(int, stdin.readline().split())
def ns(): return stdin.readline().strip()

n = int(stdin.readline())
a = list(na())
ai = []
for i, _ in enumerate(a): ai.append((_,i))
ai.sort()

for i in range(n-1,-1,-1):
    print(ai[i][1]+1)
