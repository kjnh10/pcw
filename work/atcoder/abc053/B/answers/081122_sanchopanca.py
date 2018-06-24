from sys import stdin

s = stdin.readline().strip()

l = s.find('A')
r = s.rfind('Z')
print(r - l + 1)
