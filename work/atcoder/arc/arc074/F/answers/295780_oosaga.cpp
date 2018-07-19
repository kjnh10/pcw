#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;

const int MAXN = 20005;
struct maxflow{
	struct edg{int pos, cap, rev;};
	vector<edg> gph[MAXN];

	void clear(){
		for(int i=0; i<MAXN; i++){
			gph[i].clear();
		}
	}

	void add_edge(int s, int e, int x){
		gph[s].push_back({e, x, (int)gph[e].size()});
		gph[e].push_back({s, 0, (int)gph[s].size()-1});
	}

	int dis[MAXN], pnt[MAXN];

	bool bfs(int src, int sink){
		memset(dis, 0, sizeof(dis));
		memset(pnt, 0, sizeof(pnt));
		queue<int> que;
		que.push(src);
		dis[src] = 1;
		while(!que.empty()){
			int x = que.front();
			que.pop();
			for(int i=0; i<gph[x].size(); i++){
				edg e = gph[x][i];
				if(e.cap > 0 && !dis[e.pos]){
					dis[e.pos] = dis[x] + 1;
					que.push(e.pos);
				}
			}
		}
		return dis[sink] > 0;
	}

	int dfs(int x, int sink, int f){
		if(x == sink) return f;
		for(; pnt[x] < gph[x].size(); pnt[x]++){
			edg e = gph[x][pnt[x]];
			if(e.cap > 0 && dis[e.pos] == dis[x] + 1){
				int w = dfs(e.pos, sink, min(f, e.cap));
				if(w){
					gph[x][pnt[x]].cap -= w;
					gph[e.pos][e.rev].cap += w;
					return w;
				}
			}
		}
		return 0;
	}

	lint match(int src, int sink){
		lint ret = 0;
		while(bfs(src, sink)){
			int r;
			while((r = dfs(src, sink, 2e9))) ret += r;
		}
		return ret;
	}
}mf;

int n, m;
char str[105][105];

int main(){
	cin >> n >> m;
	for(int i=0; i<n; i++) cin >> str[i];
	vector<pi> v;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(str[i][j] == '.') continue;
			v.push_back(pi(i, j));
		}
	}
	int st = -1, ed = -1;
	for(int i=0; i<v.size(); i++){
		mf.add_edge(2*i, 2*i+1, 1);
		if(str[v[i].first][v[i].second] == 'S'){
			st = 2 * i + 1;
		}
		if(str[v[i].first][v[i].second] == 'T'){
			ed = 2 * i;
		}
		for(int j=0; j<v.size(); j++){
			if(i == j) continue;
			if(v[i].first == v[j].first || v[i].second == v[j].second){
				mf.add_edge(2*i+1, 2*j, 1e9);
			}
		}
	}
	int ans = mf.match(st, ed);
	if(ans > 1e8) ans = -1;
	cout << ans << endl;
}

