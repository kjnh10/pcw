#include <bits/stdc++.h>
#define PB push_back
#define MP make_pair
#define REP(i,n) for (int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define ALL(a) (a).begin(),(a).end()
int INF=1e9;
int MOD=1e9+7;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
double EPS = 1e-10;
const int mod=1e9+7;
const double pai=3.14159265358979;
int main(){
	int n,p[1000];
	string s[1000];
	cin>>n;REP(i,n)cin>>s[i]>>p[i];
	int sum=0;
	REP(i,n)sum+=p[i];
	string ans="atcoder";
	REP(i,n)if(p[i]>sum/2)ans=s[i];
	cout<<ans<<endl;
}
