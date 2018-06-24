#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
	int n,k,temp;
	std::cin >> n >> k;
	std::vector<int> a(n,0);
	for (size_t i = 0; i < n; i++) {
		std::cin >> temp;
		a[temp-1]++;
	}
	sort(a.begin(),a.end());

	long long ans = 0;
	for (size_t i = 0; i < n-k; i++) {
		ans += a[i];
	}
	std::cout << ans << '\n';

	return 0;
}
