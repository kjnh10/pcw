#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define all(c) c.begin(),c.end()
#define pb push_back
#define fs first
#define sc second
#define show(x) cout << #x << " = " << (x) << endl
#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)
using namespace std;
template<class S,class T> ostream& operator<<(ostream& o,const pair<S,T> &p){return o<<"("<<p.fs<<","<<p.sc<<")";}
template<class T> ostream& operator<<(ostream& o,const vector<T> &vc){o<<"sz = "<<vc.size()<<endl<<"[";for(const T& v:vc) o<<v<<",";o<<"]";return o;}
int N;
vector<vector<int>> G;
vector<int> d;

void dfs(int v,int p=-1){
	if(p!=-1) d[v] = d[p]+1;
	for(int u:G[v]) if(u!=p) dfs(u,v);
}
vector<int> calcdist(int r){
	d = vector<int>(N);
	dfs(r);
	return d;
}
int main(){
	cin>>N;
	G.resize(N);
	rep(i,N-1){
		int x,y;
		cin>>x>>y;
		x--,y--;
		G[x].pb(y);
		G[y].pb(x);
	}
	vector<int> d = calcdist(0);
	int a = 0;
	rep(i,N) if(d[i]>d[a]) a = i;
	d = calcdist(a);
	int b = 0;
	rep(i,N) if(d[i]>d[b]) b = i;

	vector<int> vs;
	{
		vs.pb(b);
		int v = b;
		while(v!=a){
			for(int u:G[v]) if(d[u]+1 == d[v]){
				v = u;
				break;
			}
			vs.pb(v);
		}
	}
	int L = vs.size();
	vector<int> c(L);
	rep1(i,L-2){
		int v = vs[i];
		for(int u:G[v]) if(u!=vs[i-1] && u!=vs[i+1]){
			if(G[u].size()!=1){
				puts("-1");
				return 0;
			}
			c[i]++;
		}
	}
	vector<int> rc = c;
	reverse(all(rc));
	if(c>rc) c = rc;

	int v = 1;
	rep(i,L){
		int ov = v;
		v++;
		rep(k,c[i]) cout<<v++<<" ";
		cout<<ov<<" ";
	}
	cout<<endl;
}
