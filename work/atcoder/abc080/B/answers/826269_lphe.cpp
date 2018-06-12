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
#include "iomanip"
#include "cmath"

using namespace std;

const long long int MOD = 1000000007;

long long int N, M, K, H, W, L, R;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);


	cin >> N;
	M = N;
	while (M) {
		K += M % 10;
		M /= 10;
	}
	if (N%K) {
		cout << "No\n";
	}
	else {
		cout << "Yes\n";
	}
	return 0;
}