import collections


def ans(n):
    dist = [10 ** 5] * n
    dist[1] = 1
    d = collections.deque()
    d.append(1)
    while not d.count == 0:
        u = d.popleft()
        if u == 0:
            return dist[u]
        if dist[u] < dist[(u * 10) % n]:
            dist[(u * 10) % n] = dist[u]
            d.appendleft((u * 10) % n)
        if dist[u] < dist[(u + 1) % n]:
            dist[(u + 1) % n] = dist[u] + 1
            d.append((u + 1) % n)

n = int(input())
print(ans(n))
