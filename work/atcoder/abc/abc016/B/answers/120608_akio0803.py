A, B, C = [int(_) for _ in input().split()]

flag = 0
if A + B == C:
    flag += 1
if A - B == C:
    flag += 2

print(["!", "+", "-", "?"][flag])
