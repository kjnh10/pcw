import sys
sys.setrecursionlimit(10**9)

N = int(input())
baroons = []


for n in range(N):
  h, s = map(int, input().split())
  baroons.append((h, s))


def is_ok(X):
  T = [(X-h)//s for h, s in baroons]
  T.sort()
  for n in range(N):
    if T[n] < n:
      return False
  return True


# is_ok(start) == False, is_ok(end) == True
def bisect(start, end):
  if end - start <= 1:
    return end
  mid = (end+start)//2
  if is_ok(mid) == True:
    return bisect(start, mid)
  else:
    return bisect(mid, end)

print(bisect(0, 10**23))