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
const ll mod=1000000007;

int n;
string a,b;

int main()
{
	cin>>n;
	cin>>a>>b;
	
	ll ans=1;
	ll cur=-1;
	for(int i=0;i<n;i++){
		if(a[i]==b[i]){
			if(cur==-1){
				ans*=3;
				ans%=mod;
			}
			else if(cur==0){
				ans*=2;
				ans%=mod;
			}
			cur=0;
		}
		else{
			if(cur==-1){
				ans*=6;
				ans%=mod;
			}
			else if(cur==0){
				ans*=2;
				ans%=mod;
			}
			else{
				ans*=3;
				ans%=mod;
			}
			cur=1;
			i++;
		}
	}
	printf("%lld\n",ans);
	return 0;
}
