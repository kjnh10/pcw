class Graph:
    def __init__(self, graph):
        self.graph = graph # residual graph
        self.part_1 = len(graph)
        self.part_2 = len(graph[0])
    
    # A DFS based recursive function that returns true if a matching for vertex u is possible
    def bpm(self, u, matchR, visited):
        for v in range(self.part_2):
            if self.graph[u][v] and visited[v] == False:
                visited[v] = True
                if matchR[v] == -1 or self.bpm(matchR[v], matchR, visited):
                    matchR[v] = u
                    return True
        return False

    # Returns maximum number of matching 
    def maxBPM(self):
        matchR = [-1] * self.part_2
        result = 0
        for i in range(self.part_1):
            visited = [False] * self.part_2
            if self.bpm(i, matchR, visited):
                result += 1
        return result

N = int(input())
reds = [tuple(map(int, input().split())) for _ in range(N)]
blues = [tuple(map(int, input().split())) for _ in range(N)]

edges = [[0 for _ in range(N)] for _ in range(N)]

for i in range(N):
    for j in range(N):
        if reds[i][0] < blues[j][0] and reds[i][1] < blues[j][1]:
            edges[i][j] = 1

g = Graph(edges)

print(g.maxBPM())