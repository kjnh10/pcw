#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define all(c) c.begin(),c.end()
#define pb push_back
#define fs first
#define sc second
#define show(x) cout << #x << " = " << x << endl
#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)
using namespace std;

struct UnionFind{
	vector<int> par,rank;
	UnionFind(int N){
		par.assign(N,0);
		rank.assign(N,0);
		rep(i,N) par[i]=i;
	}
	int find(int x){
		if(par[x]==x) return x;
		return par[x]=find(par[x]);
	}
	bool same(int x,int y){
		return find(x)==find(y);
	}
	void unite(int x,int y){
		x=find(x),y=find(y);
		if(x==y) return;
		if(rank[x]<rank[y]) swap(x,y);

		//x becomes root
		par[y]=x;
		if(rank[x]==rank[y]) rank[x]++;
	}
};

int main(){
	int N,M;
	cin>>N>>M;
	vector<int> p(N);
	rep(i,N) cin>>p[i],p[i]--;
	UnionFind UF(N);
	rep(i,M){
		int x,y;
		cin>>x>>y;
		x--,y--;
		UF.unite(x,y);
	}
	int ans = 0;
	rep(i,N) if(UF.find(i) == UF.find(p[i])) ans++;
	cout<<ans<<endl;
}