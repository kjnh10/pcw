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

int n,W,C;
vector<P> b[55];
int bs[55];
int pre[55][11111];
int dp[2][55][11111];

int main(){
	cin.sync_with_stdio(false);
	cin>>n>>W>>C;
	rep(i,n){
		int w,v,c;
		cin>>w>>v>>c;
		c--;
		b[c].pb(P(w,v));
	}
	rep(c,55)bs[c]=b[c].size();
	int crt=0,next=1;
	memset(dp,0,sizeof(dp[crt]));
	rep(c,55){
		rep(i,C+1)rep(j,W+1)dp[next][i][j]=(i==0?0:dp[crt][i-1][j]);
		repl(i,1,C+1)rep(k,bs[c])for(int j=W;j>=b[c][k].fi;j--){
			maxch(dp[next][i][j],dp[next][i][j-b[c][k].fi]+b[c][k].se);
		}
		rep(i,C+1)rep(j,W+1){
			maxch(dp[next][i][j],dp[crt][i][j]);
		}
		swap(crt,next);
	}
	cout<<dp[crt][C][W]<<endl;
	return 0;
}
