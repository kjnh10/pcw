n = int(input().strip())
k = int(input().strip())
xs = [int(x) for x in input().strip().split()]

total = 0
for x in xs:
    if x < abs(x-k):
        total += x*2
    else:
        total += abs(x-k)*2
print(total)
