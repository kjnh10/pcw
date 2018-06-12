#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#define rep(i, n) for (i = 0; i < n; i++)
using namespace std;

int n;
bool isPrime[55556];
vector<int> primes;

signed main() {
	int i, j;
	
	cin >> n;
	
	rep(i, 55556) isPrime[i] = true;
	isPrime[0] = isPrime[1] = false;
	rep(i, 55556) {
		if (isPrime[i]) {
			for (j = i * 2; j < 55556; j += i)
				isPrime[j] = false;
		}
	}
	
	rep(i, 55556) if (isPrime[i]) primes.push_back(i);
	
	vector<int> ans;
	rep(i, primes.size()) if (primes[i] % 5 == 1) ans.push_back(primes[i]);
	
	rep(i, n) {
		cout << ans[i];
		if (i + 1 < n) cout << " ";
	}
	cout << endl;
	return 0;
}