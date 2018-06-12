s = input()
len_s = len(s)
n = 2**(len_s-1)
total = 0
for i in range(n):
    buf = s[0]
    for j in range(len_s-1):
        if i & (2**j):
            total += int(buf)
            buf = s[j+1]
        else:
            buf += s[j+1]
    total += int(buf)
print(total)