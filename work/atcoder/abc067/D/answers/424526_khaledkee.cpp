#include <bits/stdc++.h>
using namespace std;

/***********************************************/
/* Dear online judge:
 * I've read the problem, and tried to solve it.
 * Even if you don't accept my solution, you should respect my effort.
 * I hope my code compiles and gets accepted.
 *  ___  __     _______    _______      
 * |\  \|\  \  |\  ___ \  |\  ___ \     
 * \ \  \/  /|_\ \   __/| \ \   __/|    
 *  \ \   ___  \\ \  \_|/__\ \  \_|/__  
 *   \ \  \\ \  \\ \  \_|\ \\ \  \_|\ \ 
 *    \ \__\\ \__\\ \_______\\ \_______\
 *     \|__| \|__| \|_______| \|_______|
 */
const long long mod = 1000000007;

const int mxN = 100010;
vector<int> tree[mxN];
int st[mxN],en[mxN],H[mxN],C,sz[mxN];

void dfs(int v = 0,int p = -1) {
	st[v] = C++;
	sz[v] = 1;
	for(auto u : tree[v]) if(u != p) H[u] = H[v] + 1, dfs(u,v), sz[v] += sz[u];
	en[v] = C;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N,u,v;
	cin>>N;
	for(int i = 1;i < N;i++) {
		cin>>u>>v;
		u--,v--;
		tree[u].push_back(v);
		tree[v].push_back(u);
	}
	dfs();
	vector<pair<int,int> > vec;
	for(int i = 0;i < N;i++) {
		if(st[i] <= st[N-1] && en[i] >= en[N-1]) {
			vec.push_back({H[i],i});
		}
	}
	sort(vec.begin(),vec.end());
	int sec = sz[vec[(vec.size()+1)/2].second];
	if(sec >= N - sec) {
		cout<<"Snuke\n";
	} else {
		cout<<"Fennec\n";
	}
	return 0;
}
