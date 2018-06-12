#define _USE_MATH_DEFINES
#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <cfloat>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <time.h>
#include <vector>
#include <random>
#include <list>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> i_i;
typedef pair<ll, int> ll_i;
typedef pair<int, ll> i_ll;
typedef pair<double, int> d_i;
typedef pair<ll, ll> ll_ll;
typedef pair<double, double> d_d;
struct edge { int u, v; ll w; };

ll MOD = 1000000007;
ll _MOD = 1000000009;
double EPS = 1e-10;

int main() {
	string s; cin >> s;
	int N = s.length();
	for (int l = 0; l + 2 <= N; l++)
		if (s[l] == s[l + 1]) {
			cout << l + 1 << ' ' << l + 2 << endl;
			return 0;
		}
	for (int l = 0; l + 3 <= N; l++)
		if (s[l] == s[l + 2]) {
			cout << l + 1 << ' ' << l + 3 << endl;
			return 0;
		}
	cout << -1 << ' ' << -1 << endl;
}
