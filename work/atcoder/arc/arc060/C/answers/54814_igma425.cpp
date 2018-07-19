#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define all(c) c.begin(),c.end()
#define pb push_back
#define fs first
#define sc second
#define show(x) cout << #x << " = " << x << endl
#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)
using namespace std;
template<class S,class T> ostream& operator<<(ostream& o,const pair<S,T> &p){return o<<"("<<p.fs<<","<<p.sc<<")";}
template<class T> ostream& operator<<(ostream& o,const vector<T> &vc){o<<"sz = "<<vc.size()<<endl<<"[";for(const T& v:vc) o<<v<<",";o<<"]";return o;}
typedef long long ll;
ll dp[51][51][2501];
int main(){
	int N,A;
	cin>>N>>A;
	dp[0][0][0]=1;
	rep(i,N){
		int x;
		cin>>x;
		rep(j,50) rep(k,2501) if(dp[i][j][k]){
			dp[i+1][j][k]+=dp[i][j][k];
			dp[i+1][j+1][k+x]+=dp[i][j][k];
		}
	}
	ll ans=0;
	rep1(i,N) ans+=dp[N][i][i*A];
	cout<<ans<<endl;
}
