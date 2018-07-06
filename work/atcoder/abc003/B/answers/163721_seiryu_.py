S = input()
T = input()
word = ['a', 't', 'c', 'o', 'd', 'e', 'r']
scoresS = []
scoresT = []
n = 0

for i in S:
    scoresS.append(i)
    n = n + 1

for i in T:
    scoresT.append(i)

for i in range(0,n):
    f = 0
    if scoresS[i] == '@' or scoresT[i] == '@':
        for S in word:
            if scoresS[i] == S or scoresT[i] == S:
                ans = True
                f = 1
                break
            else:
                ans = False
    if f == 1:
        continue
    if scoresS[i] == scoresT[i]:
        ans = True
    else:
        ans = False
        break

if ans:
    print("You can win")
else:
    print("You will lose")