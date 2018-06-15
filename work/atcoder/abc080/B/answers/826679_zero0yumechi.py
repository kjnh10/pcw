n = input()
t = sum([int(i) for i in list(n)])
print("Yes" if int(n) % t == 0 else "No")