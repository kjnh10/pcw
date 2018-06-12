#include <bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3f
#define EPS (1e-10)
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef pair<int,int>P;

class UnionFind {
	vector<int>par, sz;
public:
	UnionFind(int n) {
		par = sz = vector<int>(n);
		for (int i = 0; i < n; i++) {
			par[i] = i;
			sz[i] = 1;
		}
	}
	int find(int x) {
		if (par[x] == x)return x;
		return par[x] = find(par[x]);
	}
	void unite(int x, int y) {
		x = find(x); y = find(y);
		if (x == y)return;
		if (sz[x] > sz[y]) {
			par[y] = x;
			sz[x] += sz[y];
		}
		else {
			par[x] = y;
			sz[y] += sz[x];
		}
	}
	bool same(int x, int y) {
		return find(x) == find(y);
	}
	int size(int x) {
		return sz[find(x)];
	}
};
int p[200000],q[200000];
signed main(){
	int n,m;scanf("%d%d",&n,&m);
	rep(i,n){
		scanf("%d",&p[i]);p[i]--;
		q[p[i]]=i;
	}
	UnionFind uf(n);
	rep(i,m){
		int x,y;scanf("%d%d",&x,&y);x--;y--;
		uf.unite(x,y);
	}
	int ans=0;
	rep(i,n){
		if(uf.same(i,q[i]))ans++;
	}
	cout<<ans<<endl;
}