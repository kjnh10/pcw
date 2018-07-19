#include<bits/stdc++.h>
#define MOD 1000000007
#define rep(i,n)for(int i=0;i<(n);i++)
using namespace std;
typedef long long ll;

ll fact[10002];
int main(){
	int n;scanf("%d",&n);
	fact[0]=1;
	for(int i=1;i<=n;i++)fact[i]=(fact[i-1]*i)%MOD;
	map<int,int>mp;
	vector<int>v;
	rep(i,n){
		int t;scanf("%d",&t);
		v.push_back(t);
		mp[t]++;
	}
	sort(v.begin(),v.end());
	ll ans=1,cnt=0,tim=0;
	rep(i,n){
		tim+=v[i];
		cnt+=tim;
	}
	for(auto p:mp){
		(ans*=fact[p.second])%=MOD;
	}
	cout<<cnt<<endl<<ans<<endl;
}
