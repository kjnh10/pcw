#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	
	ll a, b;
	cin >> a >> b;
	a -= 2;
	b -= 2;
	if (a == -1) {a = 1;}
	if (b == -1) {b = 1;}
	cout << a*b;
	
	return 0;
}