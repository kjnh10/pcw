#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <iostream>
#include <set>
#include <map>
using namespace std;
typedef long long ll;

int N;

bool isPrime(int x) {
	if (x < 2) return false;
	for (int i = 2; i * i <= x; i++) {
		if (x % i == 0) return false;
	}
	return true;
}

int main(int argc, char const *argv[]) {
	cin >> N;
	if (isPrime(N)) {
		cout << "Prime" << endl;
		return 0;
	}
	else if (N == 1) {
		cout << "Not Prime" << endl;
		return 0;
	}
	else {
		int ch1 = N % 10;
		if (ch1 % 2 == 0 || ch1 == 5) {
			cout << "Not Prime" << endl;
			return 0;
		}
		
		string str = to_string(N);
		int res = 0;
		for (int i = 0; i < str.size(); i++) res += (int)str[i];
		if (res % 3 != 0) {
			cout << "Prime" << endl;
			return 0;
		}
	}
	cout << "Not Prime" << endl;
	return 0;
}