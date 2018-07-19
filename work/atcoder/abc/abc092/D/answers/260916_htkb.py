a, b = map(int, input().split())

num = 100
result = []
all_black = ["#"]*num
all_white = ["."]*num
while a > 1:
    for _ in [0]*3:
        result.append(all_black[:])
    for i in range(num-1):
        result[-1-(i%2)][i] = "."
        a -= 1
        if a == 1:
            break
result.append(all_black[:])

while b > 1:
    for _ in [0]*3:
        result.append(all_white[:])
    for i in range(num-1):
        result[-1-(i%2)][i] = "#"
        b -= 1
        if b == 1:
            break
for i in range(len(result), num):
    result.append(all_white[:])

print(100,100)
for line in result:
    print("".join(line))