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
	
	int n, d;
	cin >> n >> d;
	vi ds(n);
	trav(x, ds) cin >> x;

	vi pos(n+1, d);
	rep(i,0,n){
		pos[i+1] = ds[i]>=2*pos[i] ? pos[i] : abs(pos[i] - ds[i]);
	}

	vi suf(n+1, 1);
	rrep(i,0,n)
		suf[i] = suf[i+1] + (ds[i]>=2*suf[i+1] ? 0 : ds[i]);

	int q;
	cin >> q;
	rep(_,0,q){
		int x;
		cin >> x;
		if(pos[x-1] >= suf[x]) puts("YES");
		else puts("NO");
	}
}