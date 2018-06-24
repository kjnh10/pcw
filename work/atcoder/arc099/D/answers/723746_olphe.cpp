#include "iostream"
#include "climits"
#include "list"
#include "queue"
#include "stack"
#include "set"
#include "functional"
#include "algorithm"
#include "string"
#include "map"
#include "unordered_map"
#include "unordered_set"
#include "iomanip"
#include "cmath"
#include "random"
#include "bitset"
#include "cstdio"

using namespace std;

const long long int MOD = 1000000007;
const long double EPS = 1e-8;

long long int N, M, K, H, W, L, R;

long long int digit_sum(long long int n) {
	int a = 0;
	while (n) {
		a += n % 10;
		n /= 10;
	}
	return a;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> K;
	vector<long long int>v;
	for (int i = 1; i < 10; i++)v.push_back(i);
	v.push_back(19);
	long long int last = 19;
	while (v.size() < K) {
		long long int p = digit_sum(last);
		long long int box = last / p;
		long long int add = 1;
		while ((last + add)*digit_sum(last + add * 2) > (last + add * 2)*digit_sum(last + add)) {
			add *= 10;
		}
		last += add;
		v.push_back(last);
	}
	//for (auto i : v) {
	//	cout << (long double)i / digit_sum(i) << endl;
	//}
	for (int i = 0; i < K; i++) {
		cout << v[i] << endl;
	}
	return 0;
}