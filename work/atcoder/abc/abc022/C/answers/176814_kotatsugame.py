import numpy as c,scipy.sparse.csgraph as d
N,M=map(int,input().split());f=1e9;D=c.array([[f]*N]*N)
for _ in[0]*M:u,v,l=map(int,input().split());D[u-1,v-1]=D[v-1,u-1]=l
K=c.array(D);K[:][0]=K[0][:]=[f]*N;K=d.floyd_warshall(K);s=min(min(D[0,i]+D[0,j]+K[i,j]for j in range(i+1,N))for i in range(1,N-1));print(int([-1,s][s<f]))