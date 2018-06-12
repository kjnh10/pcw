# D
n = int(input())
a_list = list(map(int, input().split()))

p = max(a_list)
gap = p
q = p
for i in range(n):
    gap_ = abs(a_list[i] - p / 2)
    if gap_ < gap and a_list[i] != p:
        gap = gap_
        q = a_list[i]
print(" ".join([str(p), str(q)]))