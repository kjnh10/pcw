X = int(input())

sum = 0
for i in range(1, X+1):
    sum += i;
    if sum >= X:
        break

print(i)