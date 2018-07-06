#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;
const int mod = 1e9 + 7;

int n, m;
vector<pi> v[305];
int dp[305][305][305];

int* get_mem(int a, int b, int c, int d){
	vector<int> v = {b, c, d};
	sort(v.begin(), v.end());
	b = v[0], c = v[1], d = v[2];
	return &dp[a][b][c];
}

int f(int pos, int lr, int lg, int lb){
	int *k = get_mem(pos, lr, lg, lb);
	if(*k != -1) return *k;
	vector<int> w = {lr, lg, lb};
	sort(w.begin(), w.end());
	for(auto &i : v[pos]){
		if(i.first <= w[0]){
			if(i.second != 3) return *k = 0;
		}
		else if(i.first <= w[1]){
			if(i.second != 2) return *k = 0;
		}
		else if(i.first <= w[2]){
			if(i.second != 1) return *k = 0;
		}
	}
	if(pos == n) return *k = 1;
	int ret = (f(pos + 1, pos + 1, lg, lb) + f(pos + 1, lr, pos + 1, lb)) % mod + f(pos + 1, lr, lg, pos + 1);
	return *k = ret % mod;
}

int main(){
	cin >> n >> m;
	for(int i=0; i<m; i++){
		int s, e, x;
		cin >> s >> e >> x;
		v[e].push_back(pi(s, x));
	}
	memset(dp, -1, sizeof(dp));
	cout << f(0, 0, 0, 0) << endl;
}
