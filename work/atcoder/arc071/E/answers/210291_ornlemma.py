import sys

cin = sys.stdin
# cin = open("in.txt", "r")


S = cin.readline().strip()
T = cin.readline().strip()
q = int(cin.readline())

def ABcnt(S):
    ls = len(S)
    cnt = 0
    Rcnt = [0]*(ls+1)
    for i in range(ls):
        if S[i]=='A':
            cnt += 1
        else:
            cnt -= 1
        Rcnt[i+1] = cnt
    return Rcnt

Scnt = ABcnt(S)
Tcnt = ABcnt(T)

for i in range(q):
    a,b,c,d = map(int, cin.readline().split())
    Stotal = (Scnt[b]-Scnt[a-1]) % 3
    Ttotal = (Tcnt[d]-Tcnt[c-1]) % 3
    if Stotal==Ttotal:
        print('YES')
    else:
        print('NO')
