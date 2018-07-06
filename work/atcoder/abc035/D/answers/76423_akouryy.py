import queue as Q
from sys import stdin, stdout

n, m, t = stdin.readline().split()
N = int(n)
T = int(t)
A = stdin.readline().split()

r = range(N)
paths = [[] for i in r]
pathsRev = [[] for i in r]

for line in stdin:
    a, b, c = line.split()
    a = int(a) - 1
    b = int(b) - 1
    c = int(c)
    paths[a].append((b, c))
    pathsRev[b].append((a, c))

q = Q.PriorityQueue()

q.put((0, 0))
costs = [-1] * N
while not q.empty():
    cost, town = q.get()
    if costs[town] == -1:
        costs[town] = cost
        for nxt, dist in paths[town]:
            if costs[nxt] == -1: q.put((cost + dist, nxt))

q.put((0, 0))
costsRev = [-1] * N
while not q.empty():
    cost, town = q.get()
    if costsRev[town] == -1:
        costsRev[town] = cost
        for nxt, dist in pathsRev[town]:
            if costsRev[nxt] == -1: q.put((cost + dist, nxt))

stdout.write(str(max(
    (T - costs[town] - costsRev[town]) * int(A[town]) for town in r if costs[town] != -1 and costsRev[town] != -1
)))
stdout.write("\n")
