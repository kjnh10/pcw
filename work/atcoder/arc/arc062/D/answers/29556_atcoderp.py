s = input()
g, p = 0, 0
score = 0
mp = {'p' : {'p' : 0, 'g' : 1}, 'g' : {'p' : -1, 'g' : 0}}
for c in s:    
    if p < g:
        p += 1
        a = 'p'
    else:
        g += 1
        a = 'g'
    score += mp[a][c]
print(score)
    
