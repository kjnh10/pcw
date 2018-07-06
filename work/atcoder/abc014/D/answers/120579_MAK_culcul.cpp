#include <iostream>
#include <fstream>
#include <typeinfo>
#include <vector>
#include <stack>
#include <cmath>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <iomanip>
#include <cctype>
#define syosu(x) fixed<<setprecision(x)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> P;
typedef pair<double,double> pdd;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<P> vp;
typedef vector<vp> vvp;
typedef vector<pll> vpll;
typedef pair<int,P> pip;
typedef vector<pip> vip;
const int inf=1<<30;
const ll INF=1ll<<52;
const double pi=acos(-1);
const double eps=1e-8;
const ll mod=1e9+7;
const vi emp;
const int dx[4]={0,1,0,-1},dy[4]={1,0,-1,-0};
const int DX[8]={-1,-1,-1,0,0,1,1,1},DY[8]={1,0,-1,1,-1,1,0,-1};

class RMQ_Index{
	private:
	vp rmq;
	P Query_func(int a,int b,int k,int l,int r){
		if(r<=a||b<=l) return {inf,0};
		if(a<=l&&r<=b) return rmq[k];
		else{
			int mid=(l+r)/2;
			P vl=Query_func(a,b,k*2+1,l,mid);
			P vr=Query_func(a,b,k*2+2,mid,r);
			return (vl<vr)?vl:vr;
		}
	}
	public:
	int n;
	void Init(int n_){
		n=1;
		while(n<n_) n*=2;
		rmq=vp(2*n-1,{inf,0});
		for(int i=0;i<n;i++) rmq[i+n-1].second=i;
	}
	void Update(int k,int x){
		k+=n-1;
		rmq[k].first=x;
		while(k>0){
			k=(k-1)/2;
			P L=rmq[k*2+1],R=rmq[k*2+2];
			rmq[k]=L<R?L:R;
		}
	}
	P Query(int a,int b){
		return Query_func(a,b,0,0,n);
	}
};

class Graph{
	private:
	int V;
	vvi List;
	vi e,dis;
	vb used;
	RMQ_Index lev;
	void Euler(int x,int l,int& ind){
		e[ind]=x;
		lev.Update(ind,l);
		used[x]=1;
		if(dis[x]==-1) dis[x]=ind;
		ind++;
		for(int i=0;i<List[x].size();i++){
			int v=List[x][i];
			if(!used[v]){
				Euler(v,l+1,ind);
				e[ind]=x;
				lev.Update(ind,l);
				ind++;
			}
		}
	}
	void LCA_Prepare(){
		e=vi(2*V-1);
		dis=vi(V,-1);
		lev.Init(2*V-1);
		used=vb(V,0);
		int ind=0;
		Euler(0,0,ind);
	}
	int LCA(int s,int t){
		return e[lev.Query(min(dis[s],dis[t]),max(dis[s],dis[t])+1).second];
	}
	vi Rank(int v){
		vi rank(V);
		used=vb(V,0);
		queue<P> q;
		q.push({v,0});
		used[v]=1;
		while(!q.empty()){
			P p=q.front();
			q.pop();
			int u=p.first;
			for(int i=0;i<List[u].size();i++){
				int w=List[u][i];
				if(!used[w]){
					used[w]=1;
					rank[w]=p.second+1;
					q.push({w,p.second+1});
				}
			}
		}
		return rank;
	}
	public:
	Graph(int v){
		V=v;
		List=vvi(v);
	}
	void add_edge(int s,int t){
		List[s].push_back(t);
		List[t].push_back(s);
	}
	void solve(){
		int q;
		cin>>q;
		LCA_Prepare();
		vi rank=Rank(0);
		for(int i=0;i<q;i++){
			int a,b;
			cin>>a>>b;
			a--;b--;
			int lca=LCA(a,b);
			cout<<rank[a]+rank[b]-2*rank[lca]+1<<endl;
		}
	}
};

int n;

int main(){
	cin>>n;
	Graph g(n);
	for(int i=1;i<n;i++){
		int s,t;
		cin>>s>>t;
		g.add_edge(s-1,t-1);
	}
	g.solve();
}