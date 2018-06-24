#include <cstdio>
#include <algorithm>
#define INF (ll)1<<32
using namespace std;
typedef long long ll;
int n,m;
ll ans;
ll f(int k) {
	if (k<3)
		return INF;
	if (k%3==0)
		return 0;
	return 1;
}
int main() {
	scanf("%d %d",&n,&m);
	ans=min(f(n)*m,f(m)*n);
	for (int i=1;i<m;i++) {
		ll a=(ll)n*i,b=(ll)(n/2)*(m-i),c=(ll)(n-n/2)*(m-i);
		ans=min(ans,max(a,max(b,c))-min(a,min(b,c)));
	}
	for (int i=1;i<n;i++) {
		ll a=(ll)m*i,b=(ll)(m/2)*(n-i),c=(ll)(m-m/2)*(n-i);
		ans=min(ans,max(a,max(b,c))-min(a,min(b,c)));
	}
	printf("%lld\n",ans);
	return 0;
}