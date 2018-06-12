s = input()[:-1]

while True:
    if len(s) % 2 == 0:
        if s[:len(s)//2] == s[len(s)//2:]:
            print(len(s))
            break
    s = s[:-1]
        

