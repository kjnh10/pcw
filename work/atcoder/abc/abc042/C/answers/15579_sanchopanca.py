n, k = map(int, input().split())
d = set(input().split())

while True:
    current_digits = set(str(n))
    if current_digits & d:
        n += 1
    else:
        break

print(n)
