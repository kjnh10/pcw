from  math import factorial

n = int(input())

print(factorial(n) % (10 ** 9 + 7))
