#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define ll long long int
#define ld long double
#define pb push_back
#define mkp make_pair
#define pii pair<int, int> 
#define pll pair<long long int, long long int>
#define sci(x) scanf("%d", &x)
#define scl(x) scanf("%lld", &x)
#define fi first
#define sc second
#define deb 0

int mark[100001], A[100001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, i, j, k, x, y, z, c = 0;
	cin >> n;
	for (i = 1; i <= n; ++i) cin >> A[i];
	x = 1;
	c = 0;
	mark[1] = 1;
	while (x != 2) {
		c++;
		x = A[x];
		if (mark[x]) break;
		mark[x] = 1;
	}
	if (x == 2) cout << c << endl;
	else cout << -1 << endl;

	return 0;
}