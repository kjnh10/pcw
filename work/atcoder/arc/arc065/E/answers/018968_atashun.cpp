#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef vector<int> vi;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(int i=m;i<(n);i++)
#define ALL(c) (c).begin(),(c).end()

int N, a, b;
pii pt[100010];
ll ret;
bool rm[100010];
vector<pii> vx, vy;
set<pii> sx, sy;
map<pii, int> id;

int main() {
	scanf("%d %d %d", &N, &a, &b), --a, --b;

	rep(i, N) {
		int x, y;
		scanf("%d %d", &x, &y);
		pt[i] = mp(x-y, x+y);
		sx.insert(mp(x-y, x+y));
		sy.insert(mp(x+y, x-y));
		vx.pb(mp(x-y, x+y));
		vy.pb(mp(x+y, x-y));		
		id[pt[i]] = i;
	}

	sort(ALL(vx));
	sort(ALL(vy));

	int d = max(abs(pt[a].fi-pt[b].fi), abs(pt[a].se-pt[b].se));

	queue<int> que;
	que.push(a);
	que.push(b);

	while (!que.empty()) {
		int v = que.front(); que.pop();
		if (rm[v]) continue;
		rm[v] = true;

		int x = pt[v].fi, y = pt[v].se;

		auto it = sx.lower_bound(mp(x-d, y-d));

		while (it != sx.end()) {
			if (it->fi != x-d || it->se > y+d) break;
			que.push(id[*it]);
			sx.erase(it++);
		}

		it = sx.lower_bound(mp(x+d, y-d));
		while (it != sx.end()) {
			if (it->fi != x+d || it->se > y+d) break;
			que.push(id[*it]);
			sx.erase(it++);
		}

		it = sy.lower_bound(mp(y-d, x-d));

		while (it != sy.end()) {
			if (it->fi != y-d || it->se > x+d) break;
			que.push(id[mp(it->se, it->fi)]);
			sy.erase(it++);
		}

		it = sy.lower_bound(mp(y+d, x-d));
		while (it != sy.end()) {
			if (it->fi != y+d || it->se > x+d) break;
			que.push(id[mp(it->se, it->fi)]);
			sy.erase(it++);
		}
	}

	rep(i, N) if (rm[i]) {
		int x = pt[i].fi, y = pt[i].se;

		int rr = ret;
		auto it = lower_bound(ALL(vx), mp(x-d, y-d));
		auto it2 = upper_bound(ALL(vx), mp(x-d, y+d));
		ret += it2 - it;

		it = lower_bound(ALL(vx), mp(x+d, y-d));
		it2 = upper_bound(ALL(vx), mp(x+d, y+d));
		ret += it2 - it;

		it = lower_bound(ALL(vy), mp(y-d, x-d));
		it2 = upper_bound(ALL(vy), mp(y-d, x+d));
		ret += it2 - it;

		it = lower_bound(ALL(vy), mp(y+d, x-d));
		it2 = upper_bound(ALL(vy), mp(y+d, x+d));
		ret += it2 - it;

		if (id.count(mp(x-d, y-d))) --ret;
		if (id.count(mp(x-d, y+d))) --ret;		
		if (id.count(mp(x+d, y-d))) --ret;		
		if (id.count(mp(x+d, y+d))) --ret;	
	}

	printf("%lld\n", ret / 2);

	return 0;
}