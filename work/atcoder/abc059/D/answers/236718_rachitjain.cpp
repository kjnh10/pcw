#include <bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fo(i,n) for(i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define ll long long
#define si(x)	scanf("%d",&x)
#define sl(x)	scanf("%lld",&x)
#define ss(s)	scanf("%s",s)
#define pi(x)	printf("%d\n",x)
#define pl(x)	printf("%lld\n",x)
#define ps(s)	printf("%s\n",s)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
typedef pair<int, int>	pii;
typedef pair<ll, ll>	pl;
typedef vector<int>		vi;
typedef vector<ll>		vl;
typedef vector<pii>		vpii;
typedef vector<pl>		vpl;
typedef vector<vi>		vvi;
typedef vector<vl>		vvl;
int mpow(int base, int exp); 
void ipgraph(int m);
void dfs(int u, int par);
const int mod = 1000000007;
const int N = 3e5, M = N;
//=======================

vi g[N];
int a[N];
int b[N];
int n;
map<pl, int> dp;
int go(ll x, ll y){
	if(abs(x-y)<=1) return -1;
	return 1;
	if(x<=1 and y <=1 ) return -1;	
	int lose = 1;
	ll i = 1;
	int &ans = dp[{x,y}];
	if(ans!=0) return ans; 
	while(2*i<=x){
		int res = go(x-2*i, y+i);
		if(res==-1){
			return ans = 1;
		}
		i++;
	}
	i = 1;
	while(2*i<=y){
		int res = go(y-2*i, x+i);
		if(res==-1){
			return ans = 1;
		}
		i++;
	}
	return ans = -1;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int i,k,j;
	ll x , y;
	cin >> x >> y;
	int win = go(x, y);
	if(win==1) cout << "Alice\n";
	else cout << "Brown\n";
	
	return 0;
} 

int mpow(int base, int exp) {
	base %= mod;
	int result = 1;
	while (exp > 0) {
	if (exp & 1) result = ((ll)result * base) % mod;
	base = ((ll)base * base) % mod;
	exp >>= 1;
	}
	return result;
}

void ipgraph(int m){
	int i, u, v;
	fo(i, m){
		cin>>u>>v; 
		u++, v++;
		g[u-1].pb(v-1);
		g[v-1].pb(u-1);
	}
}

void dfs(int u, int par){
	for(int v:g[u]){
		if (v == par) continue;
		dfs(v, u);
	}
}