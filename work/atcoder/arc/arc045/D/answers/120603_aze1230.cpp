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

class RMQ{
	int n;
	vector<int> dat;
public:
	RMQ(int n_){
		n = 1;
		while(n < n_) n *= 2;
		REP(i, n*2-1){
			dat.push_back(INF);
		}
	}

	void update(int x, int i){
		i += n-1;
		dat[i] = x;
		while(i > 0){
			i = (i-1)/2;
			dat[i] = min(dat[i*2+1], dat[i*2+2]);
		}
	}

	int query(int a, int b, int l, int r, int x){
		if(a <= l && r <= b) return dat[x];
		if(r <= a || b <= l) return INF;

		int res = INF;
		res = min(query(a, b, l, (l+r)/2, x*2+1), query(a, b, (l+r)/2, r, x*2+2));
		return res;
	}
	int query(int a, int b){
		return query(a, b, 0, n, 0);
	}
};

int main(void){
	int N, M;
	int s[300300], t[300300];
	int c[300300] = {};
	vector<int> res;
	cin >> N >> M;
	RMQ rmq(N+1);
	REP(i, M){
		cin >> s[i] >> t[i]; s[i]--; t[i];
		c[s[i]]++; c[t[i]]--;
	}
	rmq.update(c[0], 0);
	FOR(i, 1, N+1){
		c[i] += c[i-1];
		rmq.update(c[i], i);
	}
	REP(i, M){
		if(rmq.query(s[i], t[i]) > 1){
			res.push_back(i+1);
		}
	}
	cout << res.size() << endl;
	REP(i, res.size()){
		cout << res[i] << endl;
	}
}
