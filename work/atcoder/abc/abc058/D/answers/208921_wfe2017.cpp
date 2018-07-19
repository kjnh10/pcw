#include <iostream>
#include <vector>
#include <string>
#include <utility>
#define ll long long int
using namespace std;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;

int main() {
	ll n, m;
	cin >> n >> m;
	ll left[n];
	ll right[m];
	ll spacer[n-1];
	ll spacec[m-1];
	for(int i = 0; i < n; i++) {
		cin >> left[i];
	}
	for(int i = 0; i < m; i++) {
		cin >> right[i];
	}
	for(int i = 0; i < n-1; i++) {
		spacer[i] = left[i+1]-left[i];
	}
	for(int i = 0; i < m-1; i++) {
		spacec[i] = right[i+1]-right[i];
	}
	ll rtotal = 0;
	ll ctotal = 0;
	for(int i = 0; i < n-1; i++) {
		ll to_add = ((i+1) * (n-1 - i)) % 1000000007;
		to_add *= spacer[i];
		rtotal += to_add;
		rtotal %= 1000000007;
	}
	for(int i = 0; i < m-1; i++) {
		ll to_add = ((i+1) * (m- 1 - i)) % 1000000007;
		to_add *= spacec[i];
		ctotal += to_add;
		ctotal %= 1000000007;
	}
	cout << (rtotal * ctotal) % 1000000007 << endl;
}
