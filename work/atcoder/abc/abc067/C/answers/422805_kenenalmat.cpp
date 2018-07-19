#include <bits/stdc++.h>

#define ll long long
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define vi vector<int>
#define vl vector<long long>
#define sz size()
#define x first
#define y second
#define pii pair<int, int>
#define pll pair<ll, ll>
#define ld long double

using namespace std;

int n;
ll a[200200], p[200200];
ll ans = (ll)1e15, sum;

int main() {
	
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		sum += a[i];
		p[i] = p[i-1] + a[i];
	}


	for(int i = 1; i < n; i++) {
		ans = min(ans, abs(p[i] - (sum - p[i])));
	}


	cout << ans << endl;


	return 0;
}