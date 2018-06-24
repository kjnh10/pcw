#include <iostream>
#include <vector>
#include <utility>
#define ll long long int
using namespace std;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	if(b - a == c - b) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}
}
