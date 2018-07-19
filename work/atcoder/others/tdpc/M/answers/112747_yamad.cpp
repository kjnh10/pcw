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

ll h,r;
bool g[22][22];
ll dp[1<<17][22][22];
ll dp2[30][22][22],tmp[22][22],res[22][22];

int main(){
	cin.sync_with_stdio(false);
	cin>>h>>r;
	rep(i,r)rep(j,r)cin>>g[i][j];
	rep(S,1<<r){
		rep(i,r)rep(j,r){
			if(((S>>i)&1)==1&&((S>>j)&1)==1){
				if(i==j)dp[S][i][j]=1;
				else{
					rep(k,r){
						if(((S>>k)&1)==1&&g[k][j]){
							dp[S][i][j]=(dp[S][i][j]+dp[(S^(1<<j))][i][k])%mod;
						}
					}
				}
			}
		}
	}

	memcpy(dp2[0],dp[(1<<r)-1],sizeof(dp2));

	rep(hoge,30){
		memset(tmp,0,sizeof(tmp));
		rep(i,r)rep(j,r)rep(k,r){
			tmp[i][j]=(tmp[i][j]+dp2[hoge][i][k]*dp2[hoge][k][j])%mod;
		}
		memcpy(dp2[hoge+1],tmp,sizeof(tmp));
	}

	rep(i,r)rep(j,r)res[i][j]=(i==j?1:0);

	for(ll nh=30;nh>=0;nh--){
		if(h&(1<<nh)){
			memset(tmp,0,sizeof(tmp));
			rep(i,r)rep(j,r)rep(k,r){
				tmp[i][j]=(tmp[i][j]+res[i][k]*dp2[nh][k][j])%mod;
			}
			memcpy(res,tmp,sizeof(tmp));
		}
	}

	cout<<res[0][0]%mod<<endl;

	return 0;
}
