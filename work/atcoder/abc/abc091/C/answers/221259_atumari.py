N = int(input())
red = [3*N] * (2*N)
blue = [-1] * (2*N)
for i in range(N):
    a, b = (int(j) for j in input().split())
    red[a] = b
for i in range(N):
    a, b = (int(j) for j in input().split())
    blue[a] = b
ans = 0
for i in range(1, 2*N):
    for j in range(blue[i]-1, -1, -1):
        if j in red and red.index(j) < i:
            ans += 1
            blue[i] = 0
            red[red.index(j)] = 3 * N
            break
print(ans)
