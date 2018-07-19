x = int(input())

up = int(x ** 0.5) + 1
max_n = 1
for i in range(1, up):
    for j in range(2, x):
        if i ** j > x:
            break
        if i ** j > max_n:
            max_n = i ** j

print(max_n)
