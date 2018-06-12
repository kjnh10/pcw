#include <bits/stdc++.h>
#include <algorithm>
#include <stdio.h>
#include <math.h>
using namespace std;

#define INF 1.1e9
#define LINF 1.1e18
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(), (v).end()
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define BIT(x,n) bitset<n>(x)
#define PI 3.14159265358979323846

typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> PP;

struct edge {
	int to, cost;
	edge(int t,int c):to(t),cost(c) {}
};

int dx[]={1,-1,0,0},dy[]={0,0,1,-1};
int ddx[]={1,1,1,0,-1,-1,-1,0},ddy[]={1,0,-1,-1,-1,0,1,1};

ll mypow(ll x,ll n,ll m) {	//xのn乗をmで割った余り
	if(n==0) return 1;
	if(n%2==0) return mypow(x*x%m,n/2,m);
	else return x*mypow(x,n-1,m)%m;
}

//-----------------------------------------------------------------------------

ll a,b;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin>>a>>b;
	ll ans=0;
	ll n=a;
	while (n<=b) {
		ans++;
		n*=2;
	}
	cout<<ans<<endl;

	return 0;
}
