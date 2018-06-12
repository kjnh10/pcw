#include<vector>
#include<cmath>
#include<map>
#include<cstdlib>
#include<iostream>
#include<sstream>
#include<fstream>
#include<string>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<set>
#include<stack>
#include<bitset>
#include<functional>
#include<ctime>
#include<queue>
#include<deque>
#include<complex>
using namespace std;
#define pb push_back
#define pf push_front
typedef long long lint;
typedef complex<double> P;
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pint;
#define All(s) s.begin(),s.end()
#define rAll(s) s.rbegin(),s.rend()
#define REP(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
lint dp[2525][2525];
lint a[2525],sum[2525];
int main()
{
	int n,K,out=0;lint inf=1145141919810364364LL;
	cin>>n>>K;
	rep(i,n) cin>>a[i];sum[0]=0;
	rep(i,n) sum[i+1]=sum[i]+a[i];
	if(K==sum[n]){
		cout<<1<<endl;return 0;
	}
	rep(i,2525) rep(j,2525) dp[i][j]=inf;dp[0][0]=0;
	rep(i,n) rep(j,i+1){
		if(dp[i][j]>=inf) continue;
		dp[i+1][j]=min(dp[i+1][j],dp[i][j]);
		if(i==0) dp[i+1][j+1]=min(dp[i+1][j+1],dp[i][j]+1);
		else dp[i+1][j+1]=min(dp[i+1][j+1],dp[i][j]+(dp[i][j]*a[i])/sum[i]+1);
	}
	rep(i,n+1){
		if(dp[n][i]<=K) out=max(out,i);
	}
	cout<<out<<endl;
}
