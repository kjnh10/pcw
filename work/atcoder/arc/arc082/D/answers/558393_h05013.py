n = int(input())
L = list(map(int,input().split()))
tf = [L[i] == i+1 for i in range(n)]

change = 0
for i in range(n):
    if tf[i] == False: continue
    if i != n-1 and tf[i+1] == True:
        tf[i] = False
        tf[i+1] = False
        change+= 1
        continue
    tf[i] = False
    change+= 1

print(change)