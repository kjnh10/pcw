#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define RI(a) scanf("%d",&a)
#define RII(a,b) scanf("%d%d",&a,&b)
#define RIII(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define IOS ios_base::sync_with_stdio(0); cin.tie(0)
#define ALL(a) a.begin(),a.end()
#define F first
#define S second
#define REP(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#ifdef leowang
#define debug(...) do{\
	fprintf(stderr,"%s - %d : (%s) = ",__PRETTY_FUNCTION__,__LINE__,#__VA_ARGS__);\
	_DO(__VA_ARGS__);\
}while(0)
template<typename I> void _DO(I&&x){cerr<<x<<endl;}
template<typename I,typename...T> void _DO(I&&x,T&&...tail){cerr<<x<<", ";_DO(tail...);}
#else
#define debug(...)
#endif
//}}}
const ll maxn=100005;
const ll maxlg=__lg(maxn)+2;
const ll INF64=8000000000000000000LL;
const int INF=2000000000;

int n;
vector<int> a;
vector<int> ans;

int main()
{
	cin>>n;
	for(int i=0;i<n;i++){
		int x;
		scanf("%d",&x);
		a.pb(x);
	}
	sort(a.begin(),a.end());
	
	for(int i=0;i<a.size()-1;i++){
		if(a[i]==a[i+1]){
			ans.pb(a[i]);
			i++;
		}
	}
	if(ans.size()<2) puts("0");
	else{
		printf("%lld\n",1LL*ans[ans.size()-1]*ans[ans.size()-2]);
	}
	return 0;
}
