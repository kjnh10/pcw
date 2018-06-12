N = input()
tot = 0
for i in range(len(N)):
    tot += int(N[i])

if int(N) % tot == 0:
    print("Yes")
else:
    print("No")