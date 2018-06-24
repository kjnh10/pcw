from collections import deque
N, C = map(int, input().split())
sushi = [tuple(map(int, input().split())) for _ in [0]*N]
normal = [sushi[0][1] - sushi[0][0]]
n_append = normal.append
cur = normal[0]
n_max = max(0, normal[0])
for (s1_pos, s1_cal), (s2_pos, s2_cal) in zip(sushi, sushi[1:]):
    cur = cur + s2_cal - (s2_pos-s1_pos)
    if n_max < cur:
        n_max = cur
    n_append(n_max)

reverse = [sushi[-1][1] - (C-sushi[-1][0])]
r_append = reverse.append
cur = reverse[0]
r_max = max(0, reverse[0])
for (s1_pos, s1_cal), (s2_pos, s2_cal) in zip(sushi[::-1], sushi[-2::-1]):
    cur = cur + s2_cal - (s1_pos-s2_pos)
    if r_max < cur:
        r_max = cur
    r_append(r_max)

result = 0
for i, (pos, cal) in enumerate(sushi[:-1]):
    result = max(result, normal[i], normal[i]-pos+reverse[N-2-i])
for i, (pos, cal) in enumerate(sushi[:0:-1]):
    result = max(result, reverse[i], reverse[i]-(C-pos)+normal[N-2-i])
result = max(result, normal[-1], reverse[-1])

print(result)