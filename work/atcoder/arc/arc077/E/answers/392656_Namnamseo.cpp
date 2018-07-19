#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pp;
typedef pair<ll,ll> pll;
void read(int& x){ scanf("%d",&x); }
void read(ll& x){ scanf("%lld",&x); }
template<typename T,typename... Args>
void read(T& a,Args&... b){ read(a); read(b...); }
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define eb emplace_back
#define x first
#define y second

int n, m;

ll cnt[100010];
ll mn [100010];

void Work(int l, int r){
	if(l < r){
		cnt[l+1] += 1; cnt[r+1] -= 1;
		mn [l+1] += -(l+1); mn[r+1] -= -(l+1);
	} else {
		cnt[l+1] += 1;
		mn [l+1] += -(l+1);
		cnt[1] += 1; cnt[r+1] -= 1;
		mn [1] += m-l-1; mn[r+1] -= m-l-1;
	}
}

int Count(int l, int r){
	if(l < r) return r-l;
	return m-(l-r);
}

int main()
{
	read(n, m);
	int a; read(a);
	ll Ans = 0;
	for(int i=2; i<=n; ++i){
		int b; read(b);
		Work(a, b);
		Ans += Count(a, b);
		a = b;
	}
	for(int i=2; i<=m; ++i) cnt[i]+=cnt[i-1], mn[i]+=mn[i-1];
	ll Mx = 0;
	for(int i=1; i<=m; ++i){
		ll v = i*1LL*cnt[i] + mn[i];
		Mx = max(Mx, v);
	}
	printf("%lld\n", Ans - Mx);
	return 0;
}
