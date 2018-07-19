#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define fo(i,n) for(i=0;i<n;++i)
#define forr(i,n) for(i=n-1;i>=0;--i)
using namespace std;

ll gcd(ll a,ll b){while(a&&b)a>b?a%=b:b%=a;return a+b;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cerr<<"First never follows"<<endl;
	ll n, k, x, y, ans;
	cin>>n>>k>>x>>y;
	if(n<=k){
		ans = n*x;
		cout<<ans<<endl;
	}
	else{
		ans = k*x;
		ans = ans + (n-k)*y;
		cout<<ans<<endl;
	}
	return 0;
}