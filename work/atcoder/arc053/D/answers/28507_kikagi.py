from string import ascii_lowercase

S = input()

flags = {c : 0 for c in ascii_lowercase}
double = 0

for c in S:
  double += flags[c]
  flags[c] ^= 1

single = sum(flags.values())

if single == 0:
  print(double * 2)
else:
  print((double // single) * 2 + 1)
