x, a, b = map(int, input().split())

if -a + b <= x:
    if -a + b <= 0:
        print('delicious')
    else:
        print('safe')
else:
    print('dangerous')