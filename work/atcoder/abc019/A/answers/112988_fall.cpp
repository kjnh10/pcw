#include<iostream>
#include<string>
#include<vector>
#include <algorithm>

using namespace std;

int main() {
	long long a, b, c;
	vector<long long> num(3);
	cin >> num[0] >> num[1] >> num[2];
	sort(num.begin(), num.end());
	cout << num[1] << endl;
	return 0;
}