#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(I,A,B) for(ll I = (A); I < (B); ++I)
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin()) //ai>=v
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin()) //ai>v
#define NUM(x,v) (POSU(x,v)-POSL(x,v))
const ll INF=1e9+7;
const ll N = 200003;
ll n,ans[N];
pair <ll,ll> x[N];

int main(){
	cin>>n;
	FOR(i,0,n){
		cin>>x[i].first;
		x[i].second=i;
	}
	sort(x,x+n);
	FOR(i,0,n){
		if(i<n/2)ans[x[i].second]=x[n/2].first;
		else ans[x[i].second]=x[n/2-1].first;
	}
	FOR(i,0,n){
		cout<<ans[i]<<endl;
	}
	return 0;
}