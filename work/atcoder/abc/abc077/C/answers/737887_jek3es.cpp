#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> a, b, c;
int main() {
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int k;
		scanf("%d", &k);
		a.push_back(-k);
	}
	for (int i = 0; i < N; i++) {
		int k;
		scanf("%d", &k);
		b.push_back(k);
	}
	for (int i = 0; i < N; i++) {
		int k;
		scanf("%d", &k);
		c.push_back(k);
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	sort(c.begin(), c.end());
	long long ans = 0;
	for (int i = 0; i < N; i++) {
		int q = b[i];
		int s = c.end() - upper_bound(c.begin(), c.end(), q);
		int t = a.end() - upper_bound(a.begin(), a.end(), -q);
		ans += (long long)s*t;
	}
	printf("%lld\n", ans);
}	