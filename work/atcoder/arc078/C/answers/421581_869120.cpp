#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<functional>
#include<queue>
#include<cmath>
using namespace std;
long long n, a[300009], minx = (1LL << 60), s, t;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) { cin >> a[i]; s += a[i]; }
	for (int i = 0; i < n - 1; i++) { t += a[i]; minx = min(minx, abs(t - (s - t))); }
	cout << minx << endl;
	return 0;
}