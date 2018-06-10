s=list(str(input()))
ans=''
for i in s:
    if i=='1':
        ans += i
    elif i=='0':
        ans += i
    elif i=='B' and ans!='':
        ans = ans[:len(ans)-1]

print(ans)