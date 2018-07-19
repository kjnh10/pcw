a_group = [1, 3, 5, 7, 8, 10, 12]
b_group = [4, 6, 9, 11]
c_group = [2]

x, y = list(map(int, input().split()))

if x in a_group and y in a_group:
    print('Yes')
elif x in b_group and y in b_group:
    print('Yes')
elif x in c_group and y in c_group:
    print('Yes')
else:
    print('No')
