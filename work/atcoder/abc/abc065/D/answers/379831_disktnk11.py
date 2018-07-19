import sys
sys.setrecursionlimit(int(2e9))
class obj:
    def __init__(self, N):
        self.fa = [i for i in range(N)]
    def find(self, x):
        if x == self.fa[x]:
            return x
        else:
            self.fa[x] = self.find(self.fa[x])
            return self.fa[x]

N = int(input())
node = [{"x":0, "y":0, "id":i} for i in range(N)]
edge = [{"u":0, "v":0, "d":0} for i in range(2*(N-1))]
ob = obj(N)
for i in range(N):
    node[i]["x"], node[i]["y"] = map(int, input().split())
    node[i]["id"] = i

xnode = sorted(node, key=lambda x:x["x"])
for i in range(N-1):
    edge[i]["u"] = xnode[i]["id"]
    edge[i]["v"] = xnode[i+1]["id"]
    edge[i]["d"] = xnode[i+1]["x"] - xnode[i]["x"]
ynode = sorted(node, key=lambda x:x["y"])
for i in range(N-1):
    edge[i+N-1]["u"] = ynode[i]["id"]
    edge[i+N-1]["v"] = ynode[i+1]["id"]
    edge[i+N-1]["d"] = ynode[i+1]["y"] - ynode[i]["y"]
dedge = sorted(edge, key=lambda x:x["d"])
ans = 0
for i in range(2*(N-1)):
    if ob.find(dedge[i]["u"]) != ob.find(dedge[i]["v"]):
        ans += dedge[i]["d"]
        ob.fa[ob.fa[dedge[i]["u"]]] = ob.fa[dedge[i]["v"]]
print(ans)