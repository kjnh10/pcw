from collections import deque
white = 0
H,W = map(int,input().split())
c = []
for i in range(H):
  s = input()
  white += s.count(".")
  c.append(s)
st = [0,0]
go = [H - 1,W - 1]

dx = [1,-1,0,0]
dy = [0,0,1,-1]
def BFS(graph,start,goal):
  que = deque()
  que.append(start)
  dist = [["Fail" for i in range(W)] for j in range(H)]
  dist[start[0]][start[1]] = 0
  while que:
    x,y = que.popleft()
    if [x,y] == goal:
      break
    else:
      for i in range(4):
        if 0 <=x+dx[i] <H and 0 <=y+dy[i] <W:
          if c[x+dx[i]][y+dy[i]] != "#" and dist[x+dx[i]][y+dy[i]] == "Fail":
            que.append([x+dx[i],y+dy[i]])
            dist[x+dx[i]][y+dy[i]] = dist[x][y]+1
  return dist[goal[0]][goal[1]]
if BFS(c,st,go) == "Fail": print(-1)
else: print(white - BFS(c,st,go) - 1)