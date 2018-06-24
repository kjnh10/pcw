n = int(input())
a = list(map(int, input().split()))
b = [0 for i in range(n)]
res = 1

for i in a:
    b[i] += 1

if n % 2 == 1:
    if b[0] != 1:
        print(0)
        exit(0)
    else:
        for i in range(2, n, 2):
            if b[i] != 2:
                print(0)
                exit(0)
            #print(res)
            res = res * 2 % (10**9 + 7)
else:
    for i in range(1, n, 2):
        if b[i] != 2:
            print(0)
            exit(0)
        res = res * 2 % (10 ** 9 + 7)
print(res)