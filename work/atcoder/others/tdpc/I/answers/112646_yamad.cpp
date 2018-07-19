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

string s;
int dp[333][333];

int main(){
	cin.sync_with_stdio(false);
	cin>>s;
	int n=s.length();
	rep(i,n-2){
		if(s.substr(i,3)=="iwi")dp[i][i+3]=3;
	}
	repl(len,4,n+1){
		rep(l,n-len+1){
			int r=l+len;
			repl(i,l,r)maxch(dp[l][r],dp[l][i]+dp[i][r]);
			if(s[l]=='i'&&s[r-1]=='i'){
				repl(i,l,r){
					if(s[i]=='w'){
						maxch(dp[l][r],dp[l+1][i]+dp[i+1][r-1]+(dp[l+1][i]==i-l-1&&dp[i+1][r-1]==r-i-2?3:0));
					}
				}
			}
		}
	}
	cout<<dp[0][n]/3<<endl;
	return 0;
}
