#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
const ll N = 100005;

ll n, ind[N], mis[N], ans, mx;
pll dt[N][2];

char col[N];
bool out[N], bl[N];

vector<ll> adj[N];
queue<ll> q;

void upd (ll C, ll V, ll T) {
	if(dt[C][0].X < V) {
		if(dt[C][0].Y != T) dt[C][1] = dt[C][0];
		dt[C][0] = {V, T};
	}
	else if(dt[C][0].Y != T && dt[C][1].X < V) {
		dt[C][1] = {V, T};
	}
}

ll get (ll C, ll T) {
	return dt[T][dt[T][0].Y == C].X;
}

void solve (ll C, ll P) {
	if(mis[C] == -1) return;
	if(!mis[C]) {
		for(auto &T : adj[C]) {
			if(T == P || out[T]) continue;
			solve(T, C);
			upd(C, get(C, T)+2-2*bl[C], T);
		}
		mis[C] = P;
	}
	else if(mis[C] != P) {
		solve(mis[C], C);
		upd(C, get(C, mis[C])+2-2*bl[C], mis[C]);
		mis[C] = -1;
	}
}

int main()
{
	scanf("%lld",&n);
	for(ll i=1;i<n;i++) {
		ll A, B;
		scanf("%lld%lld",&A,&B);
		adj[A].push_back(B); ind[B]++;
		adj[B].push_back(A); ind[A]++;
	}
	scanf("%s",col+1);
	for(ll i=1;i<=n;i++) {
		bl[i] = (col[i] == 'B');
		if(ind[i] == 1 && bl[i]) {
			out[i] = true; q.push(i);
		}
	}
	while(!q.empty()) {
		ll C = q.front(); q.pop();
		for(auto &T : adj[C]) {
			if(--ind[T] <= 1 && bl[T] && !out[T]) {
				out[T] = true; q.push(T);
			}
		}
	}
	for(ll i=1;i<=n;i++) {
		if(out[i]) continue;
		bl[i] ^= ind[i]%2;
		ans += ind[i] + !bl[i];
	}
	if(ans == 0) {puts("0"); return 0;}
	for(ll i=1;i<=n;i++) {
		if(out[i]) continue;
		solve(i, -1);
		mx = max(mx, dt[i][0].X);
	}
	printf("%lld\n", ans-mx);
}
