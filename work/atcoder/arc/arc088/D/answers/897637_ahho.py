S = input()
cnt = 0

i = len(S)//2
j = i - 1 + len(S)%2 
v = S[i]

while j >= 0 and S[i] == S[j] == v:
  i += 1
  j -= 1

res = len(S) - j - 1
print(res)