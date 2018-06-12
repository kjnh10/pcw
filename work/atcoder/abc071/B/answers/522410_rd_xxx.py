S = input()
for i in range(26):
    a = chr(ord('a') + i)
    if not a in S:
        print(a)
        break
else:
    print('None')
