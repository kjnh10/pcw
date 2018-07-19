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
int N;
vector<vector<int>> G;
vector<int> deg;
vector<bool> isw;
vector<bool> erased;
vector<int> d;
vector<bool> good;
void dfs(int v,int p=-1,int sum=0){
	sum += good[v];
	d[v] = sum;
	for(int u:G[v]) if(u!=p && !erased[u]) dfs(u,v,sum);
}

int main(){
	cin>>N;
	G.resize(N);
	deg.resize(N);
	isw.resize(N);
	erased.resize(N);
	d.resize(N);
	good.resize(N);

	rep(i,N-1){
		int x,y;
		cin>>x>>y;
		x--,y--;
		G[x].pb(y);
		G[y].pb(x);
	}
	string c;
	cin>>c;
	rep(i,N) isw[i] = (c[i]=='W');

	int Wnum = 0;
	int s = -1;
	rep(i,N) if(isw[i]){
		Wnum++;
		s = i;
	}
	if(Wnum <= 1){
		cout<<Wnum<<endl;
		return 0;
	}

	queue<int> que;

	rep(i,N){
		deg[i] = G[i].size();
		if(deg[i]<=1 && !isw[i]) que.push(i);
	}

	while(!que.empty()){
		int v = que.front();que.pop();
		if(erased[v]) continue;
		erased[v] = 1;
		deg[v] = 0;
		for(int u:G[v]){
			deg[u]--;
			if(deg[u]<=1 && !isw[u]) que.push(u);
		}
	}

	int ans = -2;
	rep(i,N) if(!erased[i]){
		ans += 2;
		bool penalty = isw[i]^(deg[i]%2==1);
		if(penalty) ans++;
		good[i] = penalty;
	}

	dfs(s);
	int ag = s;
	rep(i,N) if(!erased[i]){
		if(d[ag]<d[i]) ag = i;
	}


	dfs(ag);
	rep(i,N) if(!erased[i]){
		if(d[ag]<d[i]) ag = i;
	}
	ans -= d[ag]*2;
	cout<<ans<<endl;

}