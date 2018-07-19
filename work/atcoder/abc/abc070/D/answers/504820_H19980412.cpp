#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
int n,q,k;
vector<P>edge[100005];
ll L[100005];
void dfs(int v,int u,ll sum){
	L[v] = sum;
	rep(i,edge[v].size()){
		if(edge[v][i].fi == u) continue;
		dfs(edge[v][i].fi,v,sum+1LL*edge[v][i].sc);
	}
}
int main(){
	cin>>n;
	rep(i,n-1){
		int a,b,c; scanf("%d%d%d",&a,&b,&c);
		edge[a].pb(mp(b,c));
		edge[b].pb(mp(a,c));
	}
	cin >> q >> k;
	dfs(k,-1,0LL);
	rep(i,q){
		int a,b; scanf("%d%d",&a,&b);
		printf("%lld\n",L[a]+L[b]);
	}
}