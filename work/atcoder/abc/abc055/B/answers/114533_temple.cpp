#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <utility>
#include <functional>

using namespace std;

#define MOD 1000000007

int main() {
	long long n, ans = 1;
	cin >> n;
	
	for (int i = 1; i <= n; ++i) {
		ans *= i;
		ans %= MOD;
	}

	cout << ans << endl;

	return 0;
}