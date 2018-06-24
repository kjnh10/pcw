#include<bits/stdc++.h>
#define de(x) cout<<#x<<"="<<x<<endl;
#define dd(x) cout<<#x<<"="<<x<<" ";
#define rep(i,a,b) for(int i=a;i<(b);++i)
#define repd(i,a,b) for(int i=a;i>=(b);--i)
#define repp(i,a,b,t) for(int i=a;i<(b);i+=t)
#define ll long long
#define mt(a,b) memset(a,b,sizeof(a))
#define fi first
#define se second
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
#define pii pair<int,int>
#define pdd pair<double,double>
#define pdi pair<double,int>
#define mp(u,v) make_pair(u,v)
#define sz(a) a.size()
#define ull unsigned long long
#define ll long long
#define pb push_back
#define PI acos(-1.0)
#define qc std::ios::sync_with_stdio(false)
const int mod = 1e9+7;
const int maxn = 2e5+5;
const double EPS = 1e-6;
using namespace std;
struct node{
	int v,s;
}num[maxn];
int sum[maxn]={0};
bool cmp(node a,node b){
	return a.s<b.s;
}
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	int a;
	int t = 0;
	rep(i,0,n) {
		scanf("%d",&a);
		if(sum[a]==0) t++;
		sum[a]++;
	}
	if(t<=k) return printf("0\n"),0;
	int cnt = 0;
	rep(i,1,n+1) {
		if(sum[i]==0) continue;
		num[cnt].v = i;
		num[cnt++].s = sum[i];
	}
	sort(num,num+cnt,cmp);
	int ans = 0;
	rep(i,0,cnt){
		ans+=num[i].s;
		t--;
		if(t<=k) break;
	}
	cout<<ans<<endl;
	return 0;
}

