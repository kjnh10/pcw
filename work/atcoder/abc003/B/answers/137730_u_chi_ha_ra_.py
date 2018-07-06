atcoder = list("atcoder")
s = list(input())
t = list(input())

ans = True
for i, j in zip(s, t):
    if i == j == '@':
        continue
    elif i == '@' and j not in atcoder:
        ans = False
        break
    elif j == '@' and i not in atcoder:
        ans = False
        break
    elif i != j and i != '@' and j != '@':
        ans = False
        break
 
print("You can win" if ans else "You will lose")
