a, b = list(map(int, input().split()))

white = "."
black = "#"
wb = white+black
wremaining = a - 1
bremaining = b - 1

print("100 100")
for i in range(25):
    if bremaining >= 50:
        print(wb*50)
        bremaining -=50
    elif bremaining > 0:
        s = wb*bremaining + white*(50-bremaining)*2
        print(s)
        bremaining = 0
    else:
        print(white*100)
    print(white*100)

for i in range(25):
    print(black*100)
    if wremaining >= 50:
        print(wb*50)
        wremaining -= 50
    elif wremaining > 0:
        s = wb*wremaining + black*(50-wremaining)*2
        print(s)
        wremaining = 0
    else:
        print(black*100)