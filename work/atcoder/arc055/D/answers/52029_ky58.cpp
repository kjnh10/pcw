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
double dp[1010][1010],d2[1010][1010];
int n;
//double cal(int x,int y);

double cal2(int x,int y){
	if(y==0 || x==n) return 0.0;
	if(d2[x][y]>-0.5) return d2[x][y];
	double top=1.0/(n-x),to2=(n-x-1.0)/(n-x)/(x+1),lest=1.0-top-to2;
	double ret=max(top+to2*cal2(x+1,y-1),to2*cal2(x+1,y));
	return d2[x][y]=ret+lest*cal2(x+1,y);
}

double cal(int x,int y){
	if(y==0 || x==n) return 0.0;
	if(dp[x][y]>-0.5) return dp[x][y];
	double ret=max((x+1.0)/n+(n-x-1.0)/n*cal2(x+1,y-1),cal(x+1,y));
	return dp[x][y]=(ret+x*cal(x+1,y))/(x+1.0);
}
int main()
{
	int k;
	cin>>n>>k;
	rep(i,1010) rep(j,1010) dp[i][j]=d2[i][j]=-1.0;
	printf("%.12f\n",cal(0,k));
}
