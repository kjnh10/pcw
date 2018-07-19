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
#define x first
#define y second

int n, k;
ll arr[200010];

vector<ll> xp;

int t[200010];
int s(int x){
	int ret=0;
	while(x) ret+=t[x], x&=(x-1);
	return ret;
}

void u(int x){
	while(x<=200000) ++t[x], x+=(x&(-x));
}

int main()
{
	read(n, k);
	for(int i=1; i<=n; ++i) read(arr[i]), arr[i]+=arr[i-1], xp.pb(arr[i]-k*1LL*i);
	xp.pb(0);
	sort(all(xp)); xp.erase(unique(all(xp)), xp.end());
	ll ans=0;
	auto f=[&](ll x){
		return lower_bound(all(xp), x) - xp.begin() + 1;
	};
	u(f(0));
	for(int i=1; i<=n; ++i){
		int p=f(arr[i]-k*1LL*i);
		ans+=s(p); u(p);
	}
	printf("%lld\n", ans);
    return 0;
}
