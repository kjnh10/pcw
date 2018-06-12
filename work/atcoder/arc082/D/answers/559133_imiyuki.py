#!/usr/bin/env python3
n = int(input())
p = list(map(lambda p_i: int(p_i) - 1, input().split()))
result = 0
for i in range(n):
    if p[i] == i:
        j = i + 1
        if j >= n:
            j = i - 1
        p[i], p[j] = p[j], p[i]
        result += 1
print(result)
