#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
int n, m, a, b, c[1000000];
int main() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) { cin >> a >> b; c[a]++; c[b]++; }
	for (int i = 1; i <= n; i++)cout << c[i] << endl;
	return 0;
}