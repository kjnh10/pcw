#include"bits/stdc++.h"
using namespace std;

#define MAX 200002

int n;

vector < pair<int, int> > v;

vector<pair<int, int> > vv;

int main() {
	cin >> n;
	bool ok = false;
	for (int i = 0; i < n; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		v.push_back(make_pair(a, b));
		if (a != b) {
			ok = true;
		}
	}
	if (ok == false) {
		puts("0");
		return 0;
	}
	long long int ans = 0;
	long long int rest = 0;
	for (int i = 0; i < v.size(); i++) {
		if (v[i].first == v[i].second) {
			ans += v[i].first;
			continue;
		}
		if (v[i].first < v[i].second) {
			ans += v[i].first;
			rest += v[i].second - v[i].first;
			continue;
		}
		vv.push_back(v[i]);
	}
	long long int sum2 = 0;
	long long int mint = LLONG_MAX;
	for (int i = 0; i < vv.size(); i++) {
		sum2 += vv[i].first;
		mint = min(mint, (long long int)vv[i].second);
	}
	sum2 -= mint;
	ans += sum2;
	printf("%lld\n", ans);

	return 0;
}