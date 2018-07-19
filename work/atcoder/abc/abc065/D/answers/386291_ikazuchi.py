import sys

import numpy as np


class Graph:
    def __init__(self, N):
        self.townarrow = [i for i in range(N)]

    def find(self, x):
        if x == self.townarrow[x]:
            return x
        else:
            self.townarrow[x] = self.find(self.townarrow[x])
            return self.townarrow[x]

    def union(self, x, y):
        self.link(self.find(x), self.find(y))

    def link(self, x, y):
        self.townarrow[y] = x


N = int(input())
x = []
y = []
for i in range(N):
    a, b = map(int, input().split())
    x.append(a)
    y.append(b)

useful_road = []

l = sorted(range(N), key=lambda j: x[j])
for i in range(len(l) - 1):
    cost = min(abs(x[l[i]] - x[l[i + 1]]), abs(y[l[i]] - y[l[i + 1]]))
    useful_road.append((cost, l[i], l[i + 1]))

l = sorted(range(N), key=lambda j: y[j])
for i in range(len(l) - 1):
    cost = min(abs(x[l[i]] - x[l[i + 1]]), abs(y[l[i]] - y[l[i + 1]]))
    useful_road.append((cost, l[i], l[i + 1]))


m = 0
cost = 0
towngroup = Graph(N)
for c, i, j in sorted(useful_road):
    if towngroup.find(i) == towngroup.find(j):
        continue
    cost += c
    m += 1

    towngroup.union(i, j)

    if m == N - 1:
        print(cost)
        sys.exit()
