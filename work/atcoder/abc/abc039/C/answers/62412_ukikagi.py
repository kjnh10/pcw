def read():
  return map(int, input().split())

KEYS = "WBWBWWBWBWBW" * 3
WHITES = [0, 2, 4, 5, 7, 9, 11]
NAMES = ['Do', 'Re', 'Mi', 'Fa', 'So', 'La', 'Si']

S = input()

for i in range(len(WHITES)):
  x = WHITES[i]
  if S == KEYS[x : x+20]:
    print(NAMES[i]); break
