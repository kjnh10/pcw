N = int(input())
p_array = [int(i) for i in input().split()]
ans = 0
for j,p in enumerate(p_array):
    if j == N-1:
        if j+1 == p:
            ans += 1
        break
    if j+1 == p:
        p_array[j] = p_array[j+1]
        p_array[j+1] = p
        ans += 1
    

print(ans)
