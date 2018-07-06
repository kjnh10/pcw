from sys import exit
from itertools import product

def read():
  return map(int, input().split())

def thr(x, m, M):
  return max(m, min(x, M))

(H, W) = read()

S = []
for _ in range(H):
  S.append(input())

ans = [['#'] * W for _ in range(H)]

for i, j in product(range(H), range(W)):
  if S[i][j] == '.':
    for y, x in product(range(max(i-1, 0), min(i+2, H)), range(max(j-1, 0), min(j+2, W))):
      ans[y][x] = '.'

for i, j in product(range(H), range(W)):
  if S[i][j] == '#' and all(ans[y][x] == '.' for y, x \
      in product(range(max(i-1, 0), min(i+2, H)), range(max(j-1, 0), min(j+2, W)))):
    print("impossible"); exit()

print("possible")
for i in range(H):
  print(''.join(ans[i]))
