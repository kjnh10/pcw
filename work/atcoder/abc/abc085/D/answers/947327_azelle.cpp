#include<iostream>
#include<iomanip>
#include<math.h>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<string>
#include<bitset>
#include<random>
#define INF 1000000000ll
#define MOD 1000000007ll
#define EPS 1e-10
#define REP(i,m) for(long long i=0; i<m; i++)
#define FOR(i,n,m) for(long long i=n; i<m; i++)
#define DUMP(a) for(long long dump=0; dump<(ll)a.size(); dump++) { cout<<a[dump]; if(dump!=(ll)a.size()-1) cout<<" "; else cout<<endl; }
#define ALL(v) v.begin(),v.end()
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef long double ld;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll n,h;
	cin>>n>>h;
	vector<ll> a(n);
	vector<ll> b(n);
	REP(i,n) cin>>a[i]>>b[i];
	sort(ALL(a));
	sort(ALL(b));
	ll buf=a[n-1];
	ll ans=INF*INF;
	ll sum=0;
	REP(i,n) {
		sum+=b[n-1-i];
		ll tmp=i+1;
		if(sum<h) {
			tmp+=(h-sum-1)/buf+1;
		}
		ans=min(ans,tmp);
	}
	cout<<ans<<endl;
}
