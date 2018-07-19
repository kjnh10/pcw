n = int(input())
ans = 1
s1 = input()
s2 = input()
i = 0
last = ""
MOD = 1000000007

while i < n:
    if s1[i] == s2[i]:
        if last == "": ans = 3
        elif last == "V": ans = (ans*2) % MOD
        last = "V"
        i+= 1
    else:
        if last == "": ans = 6
        elif last == "V": ans = (ans*2) % MOD
        else: ans = (ans*3) % MOD
        last = "H"
        i+= 2
print(ans)