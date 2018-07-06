def f(s):
    if s.find('0') == -1:
        return len(s) % 2
    if s[0] == '0' and f('1' * (len(s))) == 0:
        return 1
    if s[0] == '1' and f('1' * (len(s) - 1)) == 0:
        return 1
    return 1 - f(s[1:])
b = bin(int(input()))[3:]
ans = f(b)
print(("Aoki","Takahashi")[ans])