#include <bits/stdc++.h>
#define ll long long int
#define fio ios_base::sync_with_stdio(0);cin.tie(0)
#define sd(t) scanf("%d",&t)
#define pd(t) printf("%d\n",t)
#define slld(t) scanf("%lld",&t)
#define plld(t) printf("%lld\n",t)
#define sc(t) scanf("%c",&t)
#define pb(x) push_back(x)
#define ii pair<int,int>
#define vi vector<int>
#define vvi vector<vi >
#define vii vector<ii >
#define vvii vector<vii >
#define clr(x) memset(x,0,sizeof(x))
#define rep(i,begin,end) for(__typeof(end) i=begin-(begin>end);i!=end-(begin>end);i+=1-2*(begin>end))
#define M_PI 3.14159265358979323846
#define MOD 1000000007
#define MAX 100005
#define EPS 1e-12
using namespace std;

int main()
{
	int curr=0, maxx=0;
	string s;
	int n;
	cin>>n>>s;

	for(auto it:s)
	{
		if(it=='I') curr++;
		else curr--;
		maxx = max(maxx, curr);
	}
	pd(maxx);
	return 0;
}
