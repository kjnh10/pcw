#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define repl(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repl(i,0,n)
#define each(itr,v) for(auto itr:v)
#define pb(s) push_back(s)
#define mp(a,b) make_pair(a,b)
#define all(x) (x).begin(),(x).end()
#define dbg(x) cout<<#x"="<<x<<endl
#define maxch(x,y) x=max(x,y)
#define minch(x,y) x=min(x,y)
#define uni(x) x.erase(unique(all(x)),x.end())
#define exist(x,y) (find(all(x),y)!=x.end())
#define bcnt(x) bitset<32>(x).count()

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> P;
typedef pair<P, int> PPI;
typedef pair<ll, ll> PL;
typedef pair<P, ll> PPL;

#define INF INT_MAX/3

#define MAX_N 1000

#define mod 1000000007


//// extended gcd
ll extgcd(ll a,ll b,ll& x,ll& y){
	ll d=a;
	if(b!=0){
		d=extgcd(b,a%b,y,x);
		y-=(a/b)*x;
	}else{
		x=1;y=0;
	}
	return d;
}

//// mod inverse
ll mod_inv(ll a,ll m){
	ll x,y;
	extgcd(a,m,x,y);
	return (m+x%m)%m;
}

int n;
vector<int> g[1111];
ll fac[11111];

PL dfs(int v,int pre){
	ll res=1,size=0;
	rep(i,g[v].size()){
		if(pre!=g[v][i]){
			PL tmp=dfs(g[v][i],v);
			res=(res*tmp.fi)%mod;
			res=(res*mod_inv(fac[tmp.se],mod))%mod;
			size+=tmp.se;
		}
	}
	return PL(res*fac[size]%mod,size+1);
}

int main(){
	cin.sync_with_stdio(false);
	fac[0]=1;
	rep(i,11110)fac[i+1]=fac[i]*(i+1)%mod;
	cin>>n;
	rep(i,n-1){
		int a,b;
		cin>>a>>b;
		a--; b--;
		g[a].pb(b); g[b].pb(a);
	}
	ll res=0;
	rep(i,n){
		PL tmp=dfs(i,-1);
		res=(res+tmp.fi)%mod;
	}
	cout<<res*mod_inv(2,mod)%mod<<endl;
	return 0;
}
