N = int(input())

C_list = []
S_list = []
F_list = []

for _ in range(N-1):
    c, s, f = map(int, input().split())
    C_list.append(c)
    S_list.append(s)
    F_list.append(f)

def next_station(t, c, s, f):
    if t >= s:
        if t % f == 0:
            return t + c
        else:
            return f*(t // f + 1) + c
    else:
        return s + c
    
for i in range(N):
    t = 0
    for j in range(i, N-1):
        t = next_station(t, C_list[j], S_list[j], F_list[j])
    print(t)