#!/usr/bin/env python3

s, c = [int(x) for x in input().split()]
ans = min(s, c // 2)
ans += (c - ans * 2) // 4
print(ans)
