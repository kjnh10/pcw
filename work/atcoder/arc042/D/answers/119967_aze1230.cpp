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
	double X, Y;
	int N;
	double x[11], y[11];
	cin >> X >> Y >> N;
	REP(i, N){
		cin >> x[i] >> y[i];
	}
	x[N] = x[0]; y[N] = y[0];
	double res = INF_LL;
	REP(i, N){
		double a = (y[i+1]-y[i]);
		double b = -1*(x[i+1]-x[i]);
		double c = -(y[i+1]-y[i])*x[i]+(x[i+1]-x[i])*y[i];
		res = min(res, abs(a*X+b*Y+c)/sqrt(a*a+b*b));
	}
	cout << fixed << setprecision(10) << res << endl;
}
