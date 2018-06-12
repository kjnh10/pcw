#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

using namespace std;

#define li long long int
#define ld long double
const int MX1=1e5+5;
const int MX2=1e6+5;
const li inf=4e18;
const li mod=1e9+7;

li power(li a,li b){li res=1;while(b){if(b%2)res=(res*a)%mod;
a=(a*a)%mod;b/=2;}return res;}

li mmi(li a){return power(a,mod-2);}

li cntbit(li n){li cnt=0;while(n){n&=(n-1);cnt++;}return cnt;}

void solve(){
	string s;
	cin>>s;
	sort(s.begin(),s.end());
	if(s=="abc"){
		cout<<"Yes";
	}else{
		cout<<"No";
	}
}

int main(){
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	int t=1;
	// cin>>t;
	while(t--){
		solve();
	}
	return 0;
}