N = int(input())
As = list(map(int, input().split()))

def color(a):
    if a < 400:
        return 1
    elif a < 800:
        return 2
    elif a < 1200:
        return 3
    elif a < 1600:
        return 4
    elif a < 2000:
        return 5
    elif a < 2400:
        return 6
    elif a < 2800:
        return 7
    elif a < 3200:
        return 8
    else:
        return 0

freq = [0] * 9
for a in As:
    freq[color(a)] += 1

cum = 0
for c in freq[1:]:
    if c: cum += 1
an = freq[0]

if cum == 0:
    print(1, an)
else:
    print(cum, cum + an)
