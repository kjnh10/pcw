"""
AtCoder Begginer Contest
"""
import sys
# get N
N = int(input())

# get NGS
NGS = list()
for i in range(3):
    tmp = int(input())
    if tmp <= N:
        NGS.append(tmp)

if len(NGS) == 0:
    print("YES")
    sys.exit()

NGS.sort()

if N in NGS:
    print("NO")
    sys.exit()

if len(NGS) == 3 and NGS[0] + 1 == NGS[1] and NGS[1] + 1 == NGS[2]:
    print("NO")
    sys.exit()

now_digit = N
for i in range(100):
    if now_digit <= 0:
        print("YES")
        sys.exit()

    if now_digit - 3 in NGS:
        if now_digit - 2 in NGS:
            now_digit -= 1
        else:
            now_digit -= 2
    else:
        now_digit -= 3

if now_digit <= 0:
    print("YES")
    sys.exit()

# output
print("NO")
