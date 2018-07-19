#include <stdio.h>
#include <map>
#include <set>
#include <vector>
using namespace std;

const long long mod = 1000000007;
long long comb[505][505], phi[505], pw[505], inv[505];

int N, M, K;
vector<int> G[505],I[505];
int par[505], chk[505];
vector<int> k,p;

int find(int x)
{
	if (par[x] != x) par[x] = find(par[x]);
	return par[x];
}

void dfs(int x)
{
	for (int i=0;i<G[x].size();i++){
		int y = G[x][i];
		if (chk[y]){
			bool good = 0;
			for (int j=0;j<k.size();j++) if (k[j] == y) good = 1;
			if (good) for (int j=(int)p.size()-1;j>=0;j--){
				par[(find(p[j]))] = find(I[x][i]);
				if (k[j] == y) break;
			}
		}
		else{
			k.push_back(x);
			p.push_back(I[x][i]);
			chk[x] = 1;
			dfs(y);
			k.pop_back();
			p.pop_back();
		}
	}
}

int main()
{
	scanf("%d %d %d", &N, &M, &K);

	for (int i=0;i<505;i++){
		comb[i][0] = comb[i][i] = 1;
		for (int j=1;j<i;j++) comb[i][j] = (comb[i-1][j-1] + comb[i-1][j]) % mod;
	}

	for (int i=1;i<505;i++) phi[i] = i;
	for (int i=1;i<505;i++){
		for (int j=i*2;j<505;j+=i) phi[j] = (phi[j] + mod - phi[i]) % mod;
	}

	pw[0] = 1;
	for (int i=1;i<505;i++) pw[i] = pw[i-1] * K % mod;

	inv[1] = 1;
	for (int i=2;i<505;i++) inv[i] = (mod - mod / i) * inv[mod % i] % mod;

	for (int i=1;i<=M;i++){
		int x, y; scanf("%d %d", &x, &y);
		G[x].push_back(y);
		I[x].push_back(i);
		G[y].push_back(x);
		I[y].push_back(i);
	}

	for (int i=1;i<=M;i++) par[i] = i;

	for (int i=1;i<=N;i++) if (!chk[i])
	{
		dfs(i);
	}

	long long ans = 1;
	map<int, int> sz;
	map<int, set<int> > vt;
	for (int i=1;i<=M;i++){
		sz[find(i)]++;
	}
	for (int i=1;i<=N;i++) for (int j=0;j<I[i].size();j++) vt[find(I[i][j])].insert(G[i][j]);

	for (auto &p : sz){
		if (vt[p.first].size() == p.second){
			long long c = 0;
			for (int d=1;d<=p.second;d++) if (p.second % d == 0){
				c = (c + phi[d] * pw[p.second/d]) % mod;
			}
			c = c * inv[p.second] % mod;
			ans = ans * c % mod;
		}
		else{
			ans = ans * comb[p.second+K-1][K-1] % mod;
		}
	}
	printf("%lld\n", ans);
	return 0;
}