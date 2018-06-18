#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
const int INF=(int)2e9;
const double EPS=(double)1e-9;
const double PI=(double)acos(-1.0);
const ll MOD=(ll)1e9+7;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define FOR(i,n) for(int i=0;i<n;i++)
#define REPP(i,l,r,c) for(int i=l;i<=r;i+=c)
#define REP(i,l,r) REPP(i,l,r,1)
#define FORD(i,n) for(int i=n-1;i>=0;i--)
#define REVV(i,l,r,c) for(int i=max(l,r),_m=min(l,r);i>=_m;i-=c)
#define REV(i,l,r) REVV(i,l,r,1)
#define MAX 200005
#define wa cout<<"wa"<<endl;
int irand(int lo, int hi){
	return (((double)rand())/(RAND_MAX+1.0)) * (hi-lo+1) + lo;
}

string toString(ll x) {
	stringstream ss;
	ss << x;
	return ss.str();
}

ll toNumber(string S) {
	ll ret;
	sscanf(S.c_str(),"%lld",&ret);
	return ret;
}

void base(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

int n,m;
vector<int> g[MAX];
bool vis[MAX];

int main(){
	cin>>n>>m;
	int a,b;
	bool flag = false;
	for(int i=0;i<m;i++){
		cin>>a>>b;
		g[a].pb(b);
		g[b].pb(a);
	}
	queue<ii> q;
	q.push(ii(1,2));
	while(!q.empty()){
		ii u = q.front();
		q.pop();
		int now = u.fi;
		int service = u.se;
		if (now==n){
			flag = true;
			break;
		}
		
		for(int i=0;i<g[now].size();i++){
			int to = g[now][i];
			if (vis[to]) continue;
			if (service==0) continue;
			q.push(ii(to,service-1));
			vis[to] = true;
		}
	}
	if (flag) cout<<"POSSIBLE"<<endl;
	else cout<<"IMPOSSIBLE"<<endl;
	return 0;
}

