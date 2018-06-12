from collections import Counter
n = int(input())
S = [input() for _ in range(n)]


S_Counters= [ Counter(s) for s in S]

for i in range(26):
    s =chr(ord("a")+i)
    val = min([counter[s] for counter in S_Counters])
    print(s*val ,end='')
print()