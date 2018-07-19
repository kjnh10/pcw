import sys

S = input()
center = len(S) // 2

if len(S) % 2 == 1:
    b = S[center]
    for i in range(1, center + 1):
        if S[center + i] != b or S[center - i] != b:
            print(center + i)
            sys.exit()
else:
    b = S[center - 1]
    for i in range(center):
        if S[center - 1 - i] != b or S[center + i] != b:
            print(center + i)
            sys.exit()
print(len(S))
