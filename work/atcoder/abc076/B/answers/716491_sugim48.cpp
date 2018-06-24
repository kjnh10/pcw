#include <bits/stdc++.h>
using namespace std;

#define rep(i, N) for (int i = 0; i < N; i++)
#define pb push_back
typedef long long ll;
typedef pair<int, int> i_i;
typedef pair<ll, int> ll_i;
const int MOD = 1e9 + 7;
const int INF = INT_MAX / 2;
struct edge { int v, w; };

int main() {
	int N; ll x; cin >> N >> x;
	ll z = 1;
	while (N--) z = min(z * 2, z + x);
	cout << z << endl;
}
