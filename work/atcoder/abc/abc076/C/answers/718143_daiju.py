S = input()
T = input()
ss = []
for i in range(0, len(S) - len(T) + 1):
    for j in range(len(T)):
        if S[i+j] not in ('?', T[j]):
            break
    else:
        s = S[:i] + T + S[i+len(T):]
        ss.append(s.replace('?', 'a'))
if ss:
    print(min(ss))
else:
    print('UNRESTORABLE')