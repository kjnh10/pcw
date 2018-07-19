#include "bits/stdc++.h"
#define _CRT_SECURE_NO_WARNINGS
#define rep(i,n) for(int i = 0;i < n;i++)
#define REP(i,n,k) for(int i = n;i < k;i++)
#define P(p) cout << (p) << endl;
#define sP(p) cout << setprecision(15) << fixed << p << endl;
#define Pi pair<int,int>
#define IINF 1e9
#define LINF 1e18
#define vi vector<int>
#define mp make_pair
#define pb push_back

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int dx[] = { 0, 1,0,-1 };
int dy[] = { 1, 0,-1,0 };
int dx8[] = { -1,-1,-1,0,0,1,1,1 };
int dy8[] = { -1,0,1,-1,1,-1,0,1 };

unsigned long long sttoi(std::string str) {
	unsigned long long ret;
	std::stringstream ss; ss << str;
	ss >> ret;
	return ret;
}

ull gcd(ull a, ull b) {
	if (b > a)swap(a, b);
	if (b == 0) return a;
	return gcd(b, a%b);
}

int comb(int n, int k) {
	int ans = 1;
	for (int i = 0; i < min(k, n - k); i++) {
		ans *= n - i;
		ans /= i + 1;
	}
	return ans;
}

ll mod_pow(ll n, ll p, ll mod) {
	if (p == 0) return 1 % mod;
	if (p < 2) {
		return n % mod;
	}
	else {
		ll d = 2, value = (n%mod)*(n%mod) % mod;
		while (d * 2 < p) { d *= 2;	value *= value;	value %= mod; }
		value %= mod;
		return ((value%mod) * (mod_pow(n, p - d, mod) % mod)) % mod;
	}
}

bool isPrime(int n) {
	if (n <= 1)return false;
	if (n == 2)return true;
	if (n % 2 == 0)return false;
	for (int i = 3; i*i <= n; i += 2) {
		if (n%i == 0)return false;
	}
	return true;
}

void solve() {
	int a, b, h;
	cin >> a >> b >> h;
	P((a+b)*h/2)
}

int main() {
	solve();
	return 0;
}