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
typedef pair<int,pint> tint;
#define All(s) s.begin(),s.end()
#define rAll(s) s.rbegin(),s.rend()
#define REP(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
lint dp[1010][1010];
int ma[1010][1010];
int dx[4]={1,-1,0,0},dy[4]={0,0,1,-1};
vector<tint> v;
int main()
{
	lint out=0,mo=1000000007;
	int h,w;
	scanf("%d %d",&h,&w);
	rep(i,h) rep(j,w){
		scanf("%d",&ma[i][j]);
		v.pb(mp(ma[i][j],mp(i,j)));
	}
	sort(All(v));reverse(All(v));
	rep(i,1010) rep(j,1010) dp[i][j]=1;
	rep(i,h*w){
		int x=v[i].se.fi,y=v[i].se.se;
		rep(j,4){
			int nx=x+dx[j],ny=y+dy[j];
			if(nx<0 || ny<0 || nx>=h || ny>=w || ma[nx][ny]>=ma[x][y]) continue;
			dp[nx][ny]+=dp[x][y];
			if(dp[nx][ny]>=mo) dp[nx][ny]-=mo;
		}
		out+=dp[x][y];
		if(out>=mo) out-=mo;
	}
	cout<<out<<endl;
}
