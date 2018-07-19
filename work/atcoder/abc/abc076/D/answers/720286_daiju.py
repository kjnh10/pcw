N = int(input())
tt = map(int, input().split())
vv = map(int, input().split())

v_now = 0
v_max = [v_now]
for t, v in reversed(list(zip(tt, vv))):
    for i in range(t * 2):
        if v_now + 0.5 <= v:
            v_now += 0.5
        else:
            v_now = min(v_now, v)
        v_max.append(v_now)
v_max = v_max[::-1]

v = 0
total = 0
for i in range(len(v_max) - 1):
    v0 = v_max[i]
    v1 = v_max[i+1]
    if v + 0.5 <= v1:
        if v < v0:
            total += (v + v + 0.5) * 0.25
            v += 0.5
        else:
            total += v * 0.5
    elif v > v1:
        total += (v + v - 0.5) * 0.25
        v -= 0.5
        assert v == v1, '%s %s'%(v,v1)
    else:
        total += v * 0.5
print(total)