#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
long long n, m, a, b, c, dist[2000]; vector<pair<long long, long long>>x[3000];
int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) { cin >> a >> b >> c; a--; b--; x[a].push_back(make_pair(b, c)); }
	for (int i = 0; i < n; i++)dist[i] = -(1LL << 60);
	dist[0] = 0; long long P = dist[n - 1];
	for (int i = 0; i < 8 * n; i++) {
		for (int j = 0; j < n; j++) {
			for (pair<long long, long long> k : x[j]){
				dist[k.first] = max(dist[k.first], dist[j] + k.second);
			}
		}
		if (P != dist[n - 1] && i >= 5 * n) { cout << "inf" << endl; return 0; }
		P = dist[n - 1];
	}
	cout << dist[n - 1] << endl;
	return 0;
}