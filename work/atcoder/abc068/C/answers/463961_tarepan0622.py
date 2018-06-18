n, m = map(int, input().split())

rl = [[] for x in range(n + 1)]

for _ in range(m):
    a, b = map(int, input().split())
    rl[a].append(b)
    rl[b].append(a)

now = 1
next_node = rl[now]
if n in next_node or n == 1:
    print("POSSIBLE")
    __import__("sys").exit()


for node in next_node:
    if n in rl[node]:
        print("POSSIBLE")
        __import__("sys").exit()
print("IMPOSSIBLE")
