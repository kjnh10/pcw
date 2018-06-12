N, K = input().split()
D = input().split()

s = N
n = int(N)
while 1:
    if all(c not in D for c in s):
        print(n)
        break
    else:
        n += 1
        s = str(n)
