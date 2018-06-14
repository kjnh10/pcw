from sys import stdin

n = int(stdin.readline())

s = []
for _ in range(n):
    s.append(int(stdin.readline()))

s.sort()

s_without_10s = list(filter(lambda x: x % 10 != 0, s))

maximum_result = sum(s)
if maximum_result % 10 == 0:
    if s_without_10s:
        maximum_result -= s_without_10s[0]
    else:
        maximum_result = 0

print(maximum_result)
