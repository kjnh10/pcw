w=list(input())
alpha=list('abcdefghijklmnopqrstuvwxyz')
for i in alpha:
    if w.count(i)%2 ==1:
        print('No')
        exit()
print('Yes')