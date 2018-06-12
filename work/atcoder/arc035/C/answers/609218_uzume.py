s = input()
N = len(s)
flag = True
for i in range(N // 2):
    if(s[i] != s[N-1-i] and s[i] != '*' and s[N-1-i] != '*'):
        flag = False
        break
if flag:
    print("YES")
else:
    print("NO")