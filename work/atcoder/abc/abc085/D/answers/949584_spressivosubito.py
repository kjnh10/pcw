import heapq
N, H = map(int, input().split())
buki = []
for i in range(N):
  a, b = map(int, input().split())
  heapq.heappush(buki, (-a, False))
  heapq.heappush(buki, (-b, True))

ans = 0
while H > 0:
  attack, once = heapq.heappop(buki)
  attack = -attack
  if once:
    # print("throw :" + str(attack), H, H-attack)
    H -= attack
    ans += 1
  else:
    n = (H+attack-1) // attack
    # print("slash :" + str(attack) + "*" + str(n), H, H-attack*n)
    H -= attack * n
    ans += n

print(ans)