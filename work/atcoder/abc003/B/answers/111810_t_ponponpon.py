s = input()
t = input()
k=len(s)

flag=0
for i in range(k):
    if s[i] =='@':
        if t[i]=='@':
            continue
    if s[i] == '@':
        if t[i] == 'a':
            continue
        if t[i] == 't':
            continue
        if t[i] == 'c':
            continue
        if t[i] == 'o':
            continue
        if t[i] == 'd':
            continue
        if t[i] == 'e':
            continue
        if t[i] == 'r':
            continue

    if t[i] == '@':
        if s[i] == 'a':
            continue
        if s[i] == 't':
            continue
        if s[i] == 'c':
            continue
        if s[i] == 'o':
            continue
        if s[i] == 'd':
            continue
        if s[i] == 'e':
            continue
        if s[i] == 'r':
            continue
    
    if s[i]==t[i]:
        continue

    flag=1
    break

if flag==1:
    print("You will lose")
else:
    print("You can win")