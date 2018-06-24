s = input()
k = int(input())

for i in range(97, 123):
    c = chr(i)
    a = []
    pos = 0
    while True:
        j = s.find(c, pos)
        if j == -1:
            break
        a.append(j)
        pos += 1
    cand = set()
    for fr in a:
        for to in range(fr+1, min(fr+k+1, len(s)+1)):
            cand.add(s[fr:to])
    cand = sorted(cand)
    if len(cand) >= k:
        print(cand[k-1])
        exit()
    k -= len(cand)