MOD = 1000000007
import scipy.misc as scm

R,C=map(int,input().split())
X,Y=map(int,input().split())
D,L=map(int,input().split())

def comb(n,k):
    return scm.comb(n,k,1)%MOD

ans = comb(X*Y,D)*comb(X*Y-D,L)%MOD
#集合全体

ng = ((2*comb(X*(Y-1),D)*comb(X*(Y-1)-D,L)) + \
       (2*comb((X-1)*Y,D)*comb((X-1)*Y-D,L))) %MOD
    # １つの集合
ng -= (4*(comb((X-1)*(Y-1),D)*comb((X-1)*(Y-1)-D,L)) + \
       (comb((X-2)*Y,D)*comb((X-2)*Y-D,L)) + \
       (comb(X*(Y-2),D)*comb(X*(Y-2)-D,L)))%MOD
    #２つの集合
ng += (2*comb((X-2)*(Y-1),D)*comb((X-2)*(Y-1)-D,L) + \
       2*comb((X-1)*(Y-2),D)*comb((X-1)*(Y-2)-D,L))%MOD
    #３つの集合

if X>=2 and Y>=2 :
    ng -= (comb((X-2)*(Y-2),D)*comb((X-2)*(Y-2)-D,L))%MOD
    #４つの集合

pattern=(R-X+1)*(C-Y+1)*(ans-ng)%MOD

print(pattern)