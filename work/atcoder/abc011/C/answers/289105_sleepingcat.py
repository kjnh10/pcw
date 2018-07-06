n = int(input())
ng1 = int(input())
ng2 = int(input())
ng3 = int(input())


for i in range(0,100):
    if n > 0:
        if n == ng1 or n == ng2 or n == ng3:
            ans = "NO"
            break
        elif n - 3 != ng1 and n - 3 != ng2 and n - 3 != ng3:
            n = n - 3
        elif n - 2 != ng1 and n - 2 != ng2 and n - 2 != ng3:
            n = n - 2
        elif n - 1 != ng1 and n - 1 != ng2 and n - 1 != ng3:
            n = n - 1
        else:
            ans = "NO"
            break
    else:
        ans = "YES"
        break
else:
    ans = "NO"

if i == 99 and n <= 0:
    ans = "YES"

print(ans)
