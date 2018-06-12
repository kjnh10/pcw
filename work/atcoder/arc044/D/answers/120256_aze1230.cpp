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

ll frc[114514] = {};
vector<int> A[114514];

ll frac(ll n){
	if(frc[n] != 0) return frc[n];
	if(n == 1 || n == 0) return 1;
	return frc[n] = (n * frac(n-1))%MOD;
}

ll powM(ll n, ll m){
	ll res = 1;
	if(m == 0) return 1;
	if(m % 2 == 1)
		res *= n;
	ll half = powM(n, m/2);
	res *= (half*half)%MOD;
	return res%MOD;
}

int main(void){
	int N;
	ll res = 1;
	int ml = 0;
	cin >> N;
	REP(i, N){
		int a;
		cin >> a;
		A[a].push_back(i);
		chmax(ml, a);
	}
	if(A[0].size() != 1 || A[0][0] != 0){
		cout << 0 << endl;
		return 0;
	}
	REP(i, ml){
		res = (res * powM(powM(2, A[i].size())-1, A[i+1].size()))%MOD;
		res = (res * powM(2, A[i+1].size()*(A[i+1].size()-1)/2))%MOD;
	}
	cout << res << endl;
}
