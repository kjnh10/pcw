#include <bits/stdc++.h>
#define P pair<int,int>
#define All(v) (v).begin(), (v).end()
#define pb(x) push_back(x)
typedef long long ll;
using namespace std;
const int INF = 1e9, MOD = 1e9 + 7;
const ll LINF = 1e18;
int main() {
	int x, a, b;
	cin >> x >> a >> b;
	x -= a;
	cout << x % b << endl;
	return 0;
}