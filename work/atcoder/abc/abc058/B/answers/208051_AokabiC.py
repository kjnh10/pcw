O = input()
E = input()
X = ""
for i in range(len(E)):
    X += (O[i]+E[i])
if len(O) != len(E):
    X += O[-1]

print(X)
