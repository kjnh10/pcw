#include<bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(),(x).end()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define sz(x) ((int)(x).size())

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int N = 1e5 + 5;

int n, m;
int a[300300];
ll l[300300], r[300300];
multiset <int> s;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	m = 3 * n;
	for(int i = 1; i <= m; ++i) {
		cin >> a[i];
		if(i <= n) {
			l[i] = l[i-1] + a[i];
			s.insert(a[i]);
		}
		else {
			l[i] = l[i-1];
			int mn = *s.begin();
			if(a[i] > mn) {
				l[i] -= mn;
				l[i] += a[i];
				s.erase(s.find(mn));
				s.insert(a[i]);
			}
		}
	}
	s.clear();
	for(int i = m; i >= 1; --i) {
		if(i >= m - n + 1) {
			r[i] = r[i+1] + a[i];
			s.insert(a[i]);
		}
		else {
			r[i] = r[i+1];
			int mx = *s.rbegin();
			if(a[i] < mx) {
				r[i] -= mx;
				r[i] += a[i];
				s.erase(s.find(mx));
				s.insert(a[i]);
			}
		}
	}

	ll ans = -9e18L;
	for(int i = n; i <= m - n; ++i) {
		ans = max(ans, l[i] - r[i+1]);
	}

	cout << ans;
	return 0;
}
