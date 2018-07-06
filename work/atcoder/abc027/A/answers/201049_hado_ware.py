l1, l2, l3 = map(int, input().split())

lst = [l1, l2, l3]
lst.sort()
if lst[0]==lst[1]:
    print(lst[2])
else:
    print(lst[0])