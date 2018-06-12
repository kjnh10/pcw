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
template<class S,class T> ostream& operator<<(ostream& o,const pair<S,T> &p){return o<<"("<<p.fs<<","<<p.sc<<")";}
template<class T> ostream& operator<<(ostream& o,const vector<T> &vc){o<<"sz = "<<vc.size()<<endl<<"[";for(const T& v:vc) o<<v<<",";o<<"]";return o;}

struct MaxFlow{
	using D = int;
	const D inf = 1e9;
	struct edge{
		int to;
		D cap;
		int rev;
		edge(int to,D cap,int rev):to(to),cap(cap),rev(rev){}
	};

	int V;
	vector<vector<edge>> G;
	vector<int> level,iter;

	MaxFlow(int V):V(V){
		G = vector<vector<edge>>(V);
		level = vector<int>(V);
		iter = vector<int>(V);
	}

	void add_edge(int from, int to, D cap){
		edge e1(to,cap,(int)G[to].size());
		edge e2(from,0,(int)G[from].size());
		G[from].push_back(e1);
		G[to].push_back(e2);
	}
	void bfs(int s){
		level = vector<int>(V,-1);

		queue<int> que;
		level[s]=0;
		que.push(s);
		while(!que.empty()){
			int v=que.front();
			que.pop();
			for(int i=0;i<(int)G[v].size();i++){
				edge &e=G[v][i];
				if(e.cap>0 && level[e.to]<0){
					level[e.to]=level[v]+1;
					que.push(e.to);
				}
			}
		}
	}
	D dfs(int v,int t,D f){
		if(v==t) return f;
		for(int &i=iter[v];i<(int)G[v].size();i++){
			edge &e=G[v][i];
			if(e.cap>0 && level[v]<level[e.to]){
				D d = dfs(e.to,t,min(f,e.cap));
				if(d>0){
					e.cap-=d;
					G[e.to][e.rev].cap+=d;
					return d;
				}
			}
		}
		return 0;
	}
	D max_flow(int s,int t){
		D flow=0;
		while(true){
			bfs(s);
			if(level[t]<0) return flow;
			iter = vector<int>(V,0);
			D f;
			while( (f=dfs(s,t,inf))>0 ) flow+=f;
		}
	}
};

int main(){
	int N,M;
	cin>>N>>M;
	MaxFlow MF(N*2+2);
	rep(i,M){
		int a,b;
		cin>>a>>b;
		a--,b--;
		MF.add_edge(a,b,10000);
	}
	int S = N*2, T = N*2+1;
	rep(i,N){
		MF.add_edge(S,i,10001);
		MF.add_edge(i+N,T,10001);
	}
	int ans = 2*N - MF.max_flow(S,T)%10000;
	cout<<ans<<endl;
}
