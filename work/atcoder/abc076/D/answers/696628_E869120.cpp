#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
using namespace std;
#pragma warning (disable: 4996)

int n, t[109], v[109], s[109], p[40009];
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) { cin >> t[i]; t[i] *= 2; s[i + 1] = s[i] + t[i]; }
	for (int i = 1; i <= n; i++) { cin >> v[i]; v[i] *= 2; }
	for (int i = 0; i <= s[n + 1]; i++) {
		for (int j = 1; j <= n + 1; j++) { if (s[j] >= i) { p[i] = v[j - 1]; break; } }
		for (int j = 1; j <= n + 1; j++) {
			int dst = abs(s[j] - i);
			p[i] = min(p[i], dst + min(v[j - 1], v[j]));
		}
	}
	int sum = 0;
	for (int i = 0; i <= s[n + 1]; i++)sum += p[i];
	printf("%.12Lf\n", 0.25l*sum);
	return 0;
}