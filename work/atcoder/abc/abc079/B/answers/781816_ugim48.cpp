#include <bits/stdc++.h>
#include <random>
using namespace std;

#define rep(i, N) for (int i = 0; i < N; i++)
#define pb push_back
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int, int> i_i;
typedef pair<ll, int> ll_i;
typedef pair<ll, ll> ll_ll;
const int MOD = 1e9 + 7;
const ll INF = LLONG_MAX / 2;
struct edge { int i, v, w; };

int main() {
	int N; cin >> N;
	vector<ll> a(100);
	a[0] = 2, a[1] = 1;
	for (int i = 2; i < 100; i++) a[i] = a[i - 1] + a[i - 2];
	cout << a[N] << endl;
}
