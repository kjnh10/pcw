#!/usr/bin/env python3
a, b, c, x, y = map(int, input().split())
answer = 0
if 2 * c < a + b:
    z = min(x, y)
    x -= z
    y -= z
    answer += 2 * c * z
a = min(a, 2 * c)
b = min(b, 2 * c)
answer += a * x
answer += b * y
print(answer)
