#include <bits/stdc++.h>
 
using namespace std;
 
#define SPEED ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define fileio freopen("in.in", "r", stdin),freopen("out.out", "w", stdout);
#define ll long long int
#define FF first
#define SS second
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<long long int,long long int>
#define sd(x) scanf("%d",&x)
#define slld(x) scanf("%lld",&x)
#define pd(x) printf("%d\n",x)
#define plld(x) printf("%lld\n",x)
#define pss printf
#define MOD 1000000007
#define INF 1e18
#define eps 0.00001
#define endl '\n'
#define debug(n1) cout<<n1<<endl
ll n,h;
ll a[100005],b[100005];
 
int main() {

slld(n);slld(h);
for(int i=1;i<=n;i++)
slld(a[i]),slld(b[i]);

sort(a+1,a+n+1);
sort(b+1,b+n+1);
reverse(b+1,b+n+1);
ll x=a[n];
for(int i=1;i<=n;i++)
b[i]+=b[i-1];
ll ans=INF;
for(int i=0;i<=n;i++)
	ans=min(ans,(max(h-b[i],0ll)/x)+((max(h-b[i],0ll)%x)!=0)+i);
plld(ans);
	return 0;
           } 