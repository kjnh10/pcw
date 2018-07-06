#include <bits/stdc++.h>
#define ADD(a, b) a = (a + (ll)b) % mod
#define MUL(a, b) a = (a * (ll)b) % mod
#define MAX(a, b) a = max(a, b)
#define MIN(a, b) a = min(a, b)
#define rep(i, a, b) for(int i = (a); i < (b); i++)
#define rer(i, a, b) for(int i = (a) - 1; i >= (b); i--)
#define all(a) (a).begin(), (a).end()
#define sz(v) (int)(v).size()
#define pb push_back
#define sec second
#define fst first
#define debug(fmt, ...) Print(__LINE__, ":", fmt, ##__VA_ARGS__)
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef pair<int, pi> ppi;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vl> mat;
typedef complex<double> comp;
void Print() {cout << '\n'; }
template<class FIRST, class... REST>void Print(FIRST arg, REST... rest) { 
	cout << arg << " "; Print(rest...); }
template<class T>ostream& operator<< (ostream& out, const vector<T>& v) {
	out << "[";if(!v.empty()){rep(i,0,sz(v)-1)out<<v[i]<< ", ";out<<v.back();}out << "]";return out;}
template<class S, class T>ostream& operator<< (ostream& out, const pair<S, T>& v) {
	out << "(" << v.first << ", " << v.second << ")";return out;}
const int MAX_N = 200010;
const int MAX_V = 100010;
const double eps = 1e-6;
const ll mod = 1000000007;
const int inf = 1 << 29;
const ll linf = 1LL << 60;
const double PI = 3.14159265358979323846;
///////////////////////////////////////////////////////////////////////////////////////////////////

namespace SCC {
	int n;
	vi G[MAX_N], rG[MAX_N];
	vi nG[MAX_N];//if you don't want to create a new graph, comment out
	vi vs;
	bool used[MAX_N];
	int cmp[MAX_N];
	vi C[MAX_N];//this too

	void init(int N) {
		n = N;
		rep(i, 0, n) {
			G[i].clear();
			rG[i].clear();
			nG[i].clear();
			C[i].clear();
		}
	}

	void add_edge(int from, int to) {
		G[from].push_back(to);
		rG[to].push_back(from);
	}

	void dfs(int v) {
		used[v] = true;
		rep(i, 0, (int)G[v].size()) {
			int n = G[v][i];
			if(!used[n]) dfs(n);
		}
		vs.push_back(v);
	}

	void rdfs(int v, int k) {
		used[v] = true;
		cmp[v] = k;
		//* //C
		C[k].push_back(v);
		//*/
		rep(i, 0, (int)rG[v].size()) {
			int n = rG[v][i];
			if(!used[n]) rdfs(n, k);
			//* //nG
			if(used[n] && cmp[n] < k) nG[cmp[n]].push_back(k);
			//*/
		}
	}

	int get() {
		memset(used, 0, sizeof(used));
		vs.clear();
		rep(v, 0, n) {
			if(!used[v]) dfs(v);
		}
		memset(used, 0, sizeof(used));
		fill(cmp, cmp + n, n);
		int k = 0;
		rer(i, (int)vs.size(), 0) {
			if(!used[vs[i]]) rdfs(vs[i], k++);
		}
		//* //C
		rep(i, 0, k) reverse(all(C[i]));
		//*/
	
		//* //nG
		rep(i, 0, k) {
			sort(all(nG[i]));
			nG[i].erase(unique(all(nG[i])), nG[i].end());
		}
		//*/
		return k;
	}
}

namespace MCF { //init before you use it. O(|V|^2 + |F||E|log|V|)

	struct edge { int to, cap, cost, rev; };

	int V; //num of vertex
	vector<edge> G[MAX_V];
	int h[MAX_V];
	int dist[MAX_V];
	int prevv[MAX_V], preve[MAX_V];

	void init(int v) { //other things don't have to be init.
		V = v;
		rep(i, 0, v) G[i].clear();
	}

	void add_edge(int from, int to, int cap, int cost) {
		G[from].push_back((edge){to, cap, cost, (int)G[to].size()});
		G[to].push_back((edge){from, 0, -cost, (int)G[from].size() - 1});
	}

	int get(int s, int t, int f) {
		int res = 0;
		memset(h, 0, sizeof(h));
		rep(k, 0, V) {
			rep(i, 0, V) {
				rep(j ,0, (int)G[i].size()) {
					edge &e = G[i][j];
					if(e.cap == 0) continue;
					MIN(h[e.to], h[i] + e.cost);
				}
			}
		}
		while(f > 0) {
			priority_queue<pi, vector<pi>, greater<pi> > que;
			fill(dist, dist + V, inf);
			dist[s] = 0;
			que.push(pi(0, s));
			while(!que.empty()) {
				pi p = que.top(); que.pop();
				int v = p.sec;
				if(dist[v] < p.fst) continue;
				rep(i, 0, (int)G[v].size()) {
					edge &e = G[v][i];
					if(e.cap > 0 && dist[e.to] > dist[v] + e.cost + h[v] - h[e.to]) {
						dist[e.to] = dist[v] + e.cost + h[v] - h[e.to];
						prevv[e.to] = v;
						preve[e.to] = i;
						que.push(pi(dist[e.to], e.to));
					}
				}
			}

			if(dist[t] == inf) return -1;
			rep(v, 0, V) h[v] += dist[v];

			int d = f;
			for(int v = t; v != s; v = prevv[v]) {
				d = min(d, G[prevv[v]][preve[v]].cap);
			}
			f -= d;
			res += d * h[t];
			for(int v = t; v != s; v = prevv[v]) {
				edge &e = G[prevv[v]][preve[v]];
				e.cap -= d;
				G[v][e.rev].cap += d;
			}
		}
		return res;
	}
}


int N;

void solve() {
	cin >> N;
	SCC::init(N);
	rep(i, 0, N) {
		rep(j, 0, N) {
			int a; cin >> a;
			if(!a) continue;
			SCC::add_edge(i, j);
		}
	}
	N = SCC::get();
	int s = 2 * N, t = 2 * N + 1;
	MCF::init(2 * N + 2);
	rep(i, 0, N) {
		rep(j, 0, (int)SCC::nG[i].size()) {
			int v = SCC::nG[i][j];
			MCF::add_edge(i + N, v, inf, 0);
		}
	}
	rep(i, 0, N) {
		MCF::add_edge(i, i + N, 1, -(int)SCC::C[i].size());
		MCF::add_edge(i, i + N, inf, 0);
		MCF::add_edge(s, i, inf, 0);
		MCF::add_edge(i + N, t, inf, 0);
	}
	cout << -MCF::get(s, t, 2) << "\n";
}

int main() {
#ifndef LOCAL
	ios::sync_with_stdio(false);
    cin.tie(0);
#endif
    cout << fixed;
	cout.precision(20);
#ifdef LOCAL
    freopen("in.txt", "rt", stdin);
#endif	
	solve();
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
	return 0;
}


