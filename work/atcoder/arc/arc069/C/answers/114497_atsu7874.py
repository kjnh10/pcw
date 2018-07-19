s,c = map(int, input().split())
total = min(s, c//2)
c -= total * 2
total += c//4
print(total)