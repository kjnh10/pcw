import sys
input = sys.stdin.readline

H,W = map(int,input().split())
N = int(input())
a = [int(i) for i in input().split()]

grid = [list([None for i in range(W)]) for i in range(H)]

x = 0
y = 0
i = 0

d = 1
while i<N:
    grid[y][x] = i+1
    a[i]-=1
    if a[i]==0:
        i+=1

    x+=d
    
    if x==W:
        x-=1
        y+=1
        d= -1
        
    if x==-1:
        x+=1
        y+=1
        d = 1

for r in grid:
    print(" ".join([str(i) for i in r]))
