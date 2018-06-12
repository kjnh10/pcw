#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<queue>
#include<deque>
#include<string>
#include<string.h>
#include<vector>
#include<set>
#include<map>
#include<bitset>
#include<stdlib.h>
#include<cassert>
#include<time.h>
#include<bitset>
using namespace std;
const long long mod=1000000007;
const long long inf=mod*mod;
const long long d2=(mod+1)/2;
const double EPS=1e-6;
const double PI=acos(-1.0);
int ABS(int a){return max(a,-a);}
long long ABS(long long a){return max(a,-a);}
vector<pair<int,int> >g[110000];
int v[110000];
long long ijk_L[110000];
long long ijk_R[110000];
 
long long L[110000];
long long R[110000];
int main(){
	int a,b;scanf("%d%d",&a,&b);
	int s,t;scanf("%d%d",&s,&t);s--;t--;
	for(int i=0;i<b;i++){
		int p,q,r;scanf("%d%d%d",&p,&q,&r);p--;q--;
		g[p].push_back(make_pair(q,r));
		g[q].push_back(make_pair(p,r));
	}
	for(int i=0;i<a;i++){
		ijk_L[i]=inf;
	}
	ijk_L[s]=0;
	priority_queue<pair<long long,int> > Q;
	Q.push(make_pair(0LL,s));
	L[s]=1;
	while(Q.size()){
		long long cost=-Q.top().first;
		int at=Q.top().second;
		Q.pop();
		if(v[at])continue;
		v[at]=1;
		for(int i=0;i<g[at].size();i++){
			int to=g[at][i].first;
			long long tmp=cost+g[at][i].second;
			if(!v[to]&&ijk_L[to]>=tmp){
				if(ijk_L[to]>tmp){
					ijk_L[to]=tmp;
					L[to]=L[at];
					Q.push(make_pair(-ijk_L[to],to));
				}else{
					L[to]=(L[to]+L[at])%mod;
				}
			}
		}
	}
	for(int i=0;i<a;i++){
		ijk_R[i]=inf;
		v[i]=0;
	}
	ijk_R[t]=0;
	R[t]=1;
	Q.push(make_pair(0LL,t));
	while(Q.size()){
		long long cost=-Q.top().first;
		int at=Q.top().second;
		Q.pop();
		if(v[at])continue;
		v[at]=1;
		for(int i=0;i<g[at].size();i++){
			int to=g[at][i].first;
			long long tmp=cost+g[at][i].second;
			if(!v[to]&&ijk_R[to]>=tmp){
				if(ijk_R[to]>tmp){
					ijk_R[to]=tmp;
					R[to]=R[at];
					Q.push(make_pair(-ijk_R[to],to));
				}else{
					R[to]=(R[to]+R[at])%mod;
				}
			}
		}
	}
	long long D=ijk_L[t];
	long long ret=L[t]*R[s]%mod;
	long long ng=0;
	for(int i=0;i<a;i++){
		if(ijk_L[i]+ijk_R[i]>D)continue;
		if(ijk_L[i]==ijk_R[i]){
			ng=(ng+L[i]*R[i]%mod*L[i]%mod*R[i])%mod;
		}
		for(int j=0;j<g[i].size();j++){
			if(ijk_L[i]+g[i][j].second+ijk_R[g[i][j].first]==D){
				if((ijk_L[g[i][j].first]>ijk_R[g[i][j].first])&&(ijk_L[i]<ijk_R[i])){
					ng=(ng+L[i]*R[g[i][j].first]%mod*L[i]%mod*R[g[i][j].first])%mod;
				}
			}
		}
	}
	ret=(ret+mod-ng)%mod;
	printf("%lld\n",ret);
}