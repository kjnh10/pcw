#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
long long n, a, b, K; vector<pair<long long, long long>>vec;
int main() {
	cin >> n >> K;
	for (int i = 0; i < n; i++) {
		cin >> a >> b; vec.push_back(make_pair(a, b));
	}
	sort(vec.begin(), vec.end());
	for (int i = 0; i < vec.size(); i++) {
		K -= vec[i].second;
		if (K <= 0) { cout << vec[i].first << endl; break; }
	}
	return 0;
}