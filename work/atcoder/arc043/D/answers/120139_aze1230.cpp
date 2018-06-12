#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
#include <cmath>
#include <map>
#include <set>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#define INF_LL 1e18
#define INF 1e9

#define REP(i, n) for(int i = 0;i < (n);i++)
#define FOR(i, a, b) for(int i = (a);i < (b);i++)
#define all(x) x.begin(),x.end()

using namespace std;

using ll = long long;
using PII = pair<int, int>;
using PLL = pair<ll, ll>;

const ll MOD = 1e9+7;

template<typename T>
void chmax(T &a, T &b){
	a = max(a, b);
}

template<typename T>
void chmin(T &a, T &b){
	a = min(a, b);
}

class Union_find{
private:
	vector<int> par;
	vector<int> rank;
	int n;

public:
	Union_find(int a){
		n = a;
		for(int i = 0;i < n;i++){
			par.push_back(i);
			rank.push_back(0);
		}
	}

	int find(int x){
		if(par[x] == x){
			return x;
		}else{
			return par[x] = find(par[x]);
		}
	}

	void unite(int x, int y){
		x = find(x);
		y = find(y);
		if(x == y) return;

		if(rank[x] < rank[y]){
			par[x] = y;
		}else{
			par[y] = x;
			if(rank[x] == rank[y]) rank[x]++;
		}
	}

	bool same(int x, int y){
		return find(x) == find(y);
	}
};

int main(void){
	int N;
	int D[114514];
	ll dp[114514][4] = {};
	cin >> N;
	REP(i, N){
		cin >> D[i];
	}
	sort(D, D+N);
	dp[0][0] = 1;
	FOR(i, 1, N){
		dp[i][0] += dp[i-1][0]+1;
		FOR(j, 1, 4){
			dp[i][j] += dp[i-1][j];
			int in = upper_bound(D, D+N, D[i]/2)-D;
			in--;
			if(0 <= in && in < i)
				dp[i][j] += dp[in][j-1];
			dp[i][j] %= MOD;
		}
		dp[i][0] %= MOD;
	}
	cout << dp[N-1][3] << endl;
}
