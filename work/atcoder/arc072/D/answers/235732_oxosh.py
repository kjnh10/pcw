# D
X, Y = map(int, input().split())
if X == Y:
    print('Brown')
elif abs(X - Y) == 1:
    print('Brown')
else:
    print('Alice')