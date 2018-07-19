n = int(input())
a = list(map(int, input().split()))
f = [0 for x in range(10**5 + 10)]
for i in a:
    f[i] += 1
    f[i + 1] += 1
    f[i - 1] += 1


print(max(enumerate(f), key=lambda x: x[1])[1])
