#define _USE_MATH_DEFINES
#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <cassert>
#include <cfloat>
#include <climits>
#include <complex>
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
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> i_i;
typedef pair<ll, int> ll_i;
typedef pair<double, int> d_i;
typedef pair<ll, ll> ll_ll;
typedef pair<double, double> d_d;
struct edge { int v; ll w; };

int MOD = 999999937;

bool check(int N, vector<ll>& x, vector<ll>& c, double t) {
	double x1 = -DBL_MAX, x2 = DBL_MAX;
	for (int i = 0; i < N; i++) {
		x1 = max(x1, x[i] - t / c[i]);
		x2 = min(x2, x[i] + t / c[i]);
	}
	return x1 <= x2;
}

int main() {
	int N; cin >> N;
	vector<ll> x(N), y(N), c(N);
	for (int i = 0; i < N; i++)
		cin >> x[i] >> y[i] >> c[i];
	double lb = 0, ub = 1e9;
	for (int t = 0; t < 100; t++) {
		double mid = (lb + ub) / 2;
		if (check(N, x, c, mid) && check(N, y, c, mid)) ub = mid;
		else lb = mid;
	}
	printf("%.15f\n", lb);
}
