#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pp;
typedef pair<ll,ll> pll;
void read(int& x){ scanf("%d",&x); }
void read(ll& x){ scanf("%lld",&x); }
template<typename T,typename... Args>
void read(T& a,Args&... b){ read(a); read(b...); }
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define eb emplace_back
#define x first
#define y second

int n;

int a[200010];
int rev[200010];

const int inf = 1e9;
struct SEG{
	const static int M = 262144;
	int tree[M<<1];
	SEG(){ for(int& x:tree) x=inf; }
	void put(int p, int v){
		for(p+=M; p; p/=2) tree[p]=min(tree[p], v);
	}
	int rmin(int l, int r){
		l+=M; r+=M; int ret=inf;
		while(l<=r){
			if(l%2==1) ret=min(ret, tree[l++]);
			if(r%2==0) ret=min(ret, tree[r--]);
			l/=2; r/=2;
		}
		return ret;
	}
} seg[2];

int Ind;
pp data[200010];
vector<int> edge[200010];

int solve(int l, int r){
	if(l>r) return -1;
	int m = seg[l%2].rmin(l, r); m = rev[m];
	int rb = seg[1-m%2].rmin(m+1, r); rb = rev[rb];
	int i = ++Ind;
	data[i] = {a[m], a[rb]};
	int t=solve(l, m-1); if(~t) edge[i].pb(t);
	t=solve(m+1, rb-1); if(~t) edge[i].pb(t);
	t=solve(rb+1, r); if(~t) edge[i].pb(t);
	return i;
}

priority_queue<pp>pq;

int main()
{
	read(n);
	for(int i=1; i<=n; ++i){
		read(a[i]);
		rev[a[i]]=i;
		seg[i%2].put(i, a[i]);
	}
	int p = solve(1, n);
	pq.push({0, p});
	while(pq.size()){
		int i = pq.top().second; pq.pop();
		printf("%d %d ", data[i].x, data[i].y);
		for(int j:edge[i]){
			pq.emplace(-data[j].x, j);
		}
	}
	
	return 0;
}
