//Daniel Grzegorzewski
#include <bits/stdc++.h>

#define MP make_pair
#define PB push_back
#define ST first
#define ND second

using namespace std;

typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<PII> VII;
typedef long long LL;

void init_ios()
{
     ios_base::sync_with_stdio(0);
     cin.tie(0);
}

int n, m, x, a[105];

int main()
{
	init_ios();
	cin >> n >> m >> x;
	for (int i = 1; i <= m; ++i) {
		int t;
		cin >> t;
		a[t]++;
	}
	int res = 0, res2 = 0;
	for (int i = 0; i < x; ++i)
		res += a[i];
	for (int i = x+1; i <= n; ++i)
		res2 += a[i];
	cout<<min(res, res2)<<"\n";
}