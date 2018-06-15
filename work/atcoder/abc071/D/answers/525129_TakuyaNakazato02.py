N = int(input())
S1 = input()
S2 = input()

MOD = 1000000007

if S1[0] == S2[0]:
    ans = 3
    idx = 1
    yoko = False
else:
    ans = 6
    idx = 2
    yoko = True
    
while idx < N:
    if S1[idx] == S2[idx]:
        if yoko:
            ans *= 1 
        else:
            ans *= 2
        idx += 1
        yoko = False
    else:
        if yoko:
            ans *= 3
        else:
            ans *= 2
        idx += 2
        yoko = True
    
    ans %= MOD
    
print(ans%MOD)