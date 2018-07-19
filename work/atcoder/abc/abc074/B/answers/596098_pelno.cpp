#define _USE_MATH_DEFINES

#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <utility>
#include <climits>
#include <vector>
#include <map>
using namespace std;

#define ll long long
const int MOD = 1000000007;//10^9+7

int max(int a, int b) {

	if (a > b)return a;
	else return b;

}
//aとbの大きい方

int min(int a, int b) {

	if (a < b)return a;
	else return b;

}
//aとbの小さい方

int avd_i(int a, int b) {

	if (a > b)return a - b;
	else return b - a;

}
double avd_d(double a, double b) {

	double re;
	if (a > b)re = a - b;
	else re = b - a;
	return re;

}
//aとbの差の絶対値

ll powsur(ll a, ll b, ll p) {

	if (b == 0) {

		return 1;

	}
	else if (b % 2 == 0) {

		ll d = powsur(a, b / 2, p);
		return ((d%p)*(d%p)) % p;

	}
	else {

		return ((a%p)*powsur(a, b - 1, p) % p) % p;

	}

}
//pは素数,aのb乗をpで割った余り

ll CMOD(ll n, ll r, ll p) {

	ll a = 1, b = 1, c = 1, re;
	for (int i = 1; i <= n; i++) {

		a *= i;
		a = a%p;

	}
	for (int i = 1; i <= r; i++) {

		b *= i;
		b = b%p;

	}
	for (int i = 1; i <= n - r; i++) {

		c *= i;
		c = c%p;

	}
	b = powsur(b, p - 2, p);
	c = powsur(c, p - 2, p);
	re = ((a%p)*(b%p)) % p;
	re = ((re%p)*c%p) % p;

	return re;

}
//pは素数,(nCr)%p

int main() {
	
	int N, K, X[105], ans = 0;

	cin >> N >> K;
	for (int i = 0; i < N; i++) {

		cin >> X[i];
		ans += min(X[i], K - X[i]) * 2;
	
	}

	cout << ans << endl;

	return 0;
}