#include <bits/stdc++.h>

#define _overload(_1,_2,_3,name,...) name
#define _rep(i,n) _range(i,0,n)
#define _range(i,a,b) for(int i=int(a);i<int(b);++i)
#define rep(...) _overload(__VA_ARGS__,_range,_rep,)(__VA_ARGS__)

#define _rrep(i,n) _rrange(i,n,0)
#define _rrange(i,a,b) for(int i=int(a)-1;i>=int(b);--i)
#define rrep(...) _overload(__VA_ARGS__,_rrange,_rrep,)(__VA_ARGS__)

#define _all(arg) begin(arg),end(arg)
#define uniq(arg) sort(_all(arg)),(arg).erase(unique(_all(arg)),end(arg))
#define getidx(ary,key) lower_bound(_all(ary),key)-begin(ary)
#define clr(a,b) memset((a),(b),sizeof(a))
#define bit(n) (1LL<<(n))
#define popcount(n) (__builtin_popcountll(n))

template<class T>bool chmax(T &a, const T &b) { return (a<b)?(a=b,1):0;}
template<class T>bool chmin(T &a, const T &b) { return (b<a)?(a=b,1):0;}

using namespace std;
using ll=long long;
ll dp[1<<16];

int main(void){
	int n,m;
	cin >> n >> m;
	
	vector<int> ord[22];
	rep(i,m){
		int x,y;
		cin >>  x >> y;
		ord[x-1].push_back(y-1);
	}

	dp[0]=1LL;
	rep(mask,1<<n){
		rep(i,n){
			if(mask&bit(i)) continue;
			int nmask=mask|bit(i);
			bool ok=true;
			for(auto &it:ord[i]) if(mask&bit(it)) ok=false;
			if(ok) dp[nmask]+=dp[mask];
		}
	}
	cout << dp[(1<<n)-1] << endl;
	return 0;
}