s = input()

while True:
    s = s[:-2]
    n = len(s)
    w1 = s[:int(n / 2)]
    w2 = s[int(n / 2):]
    if w1 == w2:
        print(n)
        break