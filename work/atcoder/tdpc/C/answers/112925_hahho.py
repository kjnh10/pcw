def prob(Rp, Rq):
  return 1/(1+pow(10, (Rq-Rp)/400))

K = int(input())
N = 2**K
R = [int(input()) for n in range(N)]


P = [1.0]*N

for k in range(K):
  size = 2**k
  for s in range(0, N, 2*size):
    t = s + size
    u = t + size

    nP = [0] * (u-s)

    for i in range(s,t):
      r1 = R[i]
      nP[i-s] = P[i]*sum(prob(r1, r2)*p for r2,p in zip(R[t:u], P[t:u]))

    for i in range(t,u):
      r1 = R[i]
      nP[i-s] = P[i]*sum(prob(r1, r2)*p for r2,p in zip(R[s:t], P[s:t]))

    P[s:u] = nP

for p in P:
  print(p)