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
#include <random>
#include <deque>

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

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

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
int x[114514], y[114514];
int tx[114514], ty[114514];
int N;

bool ok(int X, int Y){
	int d = abs(x[0]-X) + abs(y[0]-Y);
	REP(i, N){
		if(abs(x[i]-X) + abs(y[i]-Y) != d)
			return false;
	}
	return true;
}

int main(void){
	int xmin = INF, ymin = INF, xmax = -INF, ymax = -INF;
	int D = 0;
	cin >> N;
	REP(i, N){
		cin >> x[i] >> y[i];
		tx[i] = x[i]+y[i];
		ty[i] = x[i]-y[i];
		chmin(xmin, tx[i]); chmin(ymin, ty[i]);
		chmax(xmax, tx[i]); chmax(ymax, ty[i]);
	}
	D = max(xmax-xmin, ymax-ymin);
	xmax = xmax-D/2; xmin = xmin+D/2; ymax = ymax-D/2; ymin = ymin+D/2;
	if(ok((xmin+ymin)/2, (xmin-ymin)/2)) cout << (xmin+ymin)/2 << " " << (xmin-ymin)/2 << endl;
	else if(ok((xmin+ymax)/2, (xmin-ymax)/2)) cout << (xmin+ymax)/2 << " " << (xmin-ymax)/2 << endl;
	else if(ok((xmax+ymin)/2, (xmax-ymin)/2)) cout << (xmax+ymin)/2 << " " << (xmax-ymin)/2 << endl;
	else if(ok((xmax+ymax)/2, (xmax-ymax)/2)) cout << (xmax+ymax)/2 << " " << (xmax+ymax)/2 << endl;
	return 0;
}
