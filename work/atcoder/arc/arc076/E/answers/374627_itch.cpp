#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = a; i < (b); ++i)
#define rrep(i,a,b) for(int i = b; i --> (a);)
#define all(v) v.begin(),v.end()
#define trav(x,v) for(auto &x : v)
#define sz(v) (int)(v).size()
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int r,c,n;
	cin >> r >> c >> n;
	vector<vector<pii>> xy(n, vector<pii>(2));
	trav(v, xy){
		trav(pa, v) cin >> pa.first >> pa.second;
	}
	auto tonum = [&](pii pa){
		int x = pa.first, y = pa.second;
		if(x == 0) return y;
		if(y == c) return c+x;
		if(x == r) return c+r+(c-y);
		if(y == 0) return c+r+c+(r-x);
		return -1;
	};
	vector<pii> bs;
	rep(i,0,n){
		int a = tonum(xy[i][0]), b = tonum(xy[i][1]);
		if(a ==-1 || b == -1) continue;
		bs.emplace_back(a,i);
		bs.emplace_back(b,i);
	}
	sort(all(bs));
	stack<int> st;
	trav(pa, bs){
		if(!st.empty() && st.top()==pa.second)
			st.pop();
		else
			st.push(pa.second);
	}
	if(st.empty()) cout << "YES" << endl;
	else cout << "NO" << endl;
}