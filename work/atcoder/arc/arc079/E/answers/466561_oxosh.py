# E

N = int(input())
a_list = list(map(int, input().split()))

K = 0
R = 0

for i in range(N):
    q = a_list[i] // (N+1)
    if q >= 2:
        a_list[i] -= (q-1)*(N+1)
        R += (q-1)
        K += (q-1)

if R >= N:
    K += (R - N)*N
    R = N

for i in range(N):
    a_list[i] += R
    
while max(a_list) >= N:
    p = a_list.index(max(a_list))
    K += 1
    for i in range(N):
        if i == p:
            a_list[i] -= N
        else:
            a_list[i] += 1
    
print(K)