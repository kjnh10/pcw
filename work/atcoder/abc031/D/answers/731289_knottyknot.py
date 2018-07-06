from itertools import product

K, N = map(int, input().split())

data = []
for i in range(N):
  data.append(input().split())

def validate(length_s):
  ans = [""] * K
  for n in range(N):
    index = 0
    for c in [int(c)-1 for c in data[n][0]]:
      if index + length_s[c] > len(data[n][1]):
        return []
      if ans[c] == "":
        ans[c] = data[n][1][index:index+length_s[c]]
      elif ans[c] != data[n][1][index:index+length_s[c]]:
        return []
      index += length_s[c]
    if index != len(data[n][1]):
      return []
  return ans


for i in range(3**K):
  length_s = []
  for j in range(K):
    length_s.append(i%3 + 1)
    i //= 3
  if validate(length_s) != []:
    for w in validate(length_s):
      print(w)
    import sys
    sys.exit()