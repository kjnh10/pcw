a = [1,3,5,7,8,10,12]
b = [4,6,9,11]
c = [2]
d,e = list(map(int, input().split()))
if (d in a and e in a) or (d in b and e in b) or (d in c and e in c):
    print("Yes")
else:
    print("No")