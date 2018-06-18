#include <set>
#include <iostream>
using namespace std;
int N, M, a, b;
int main() {
	ios::sync_with_stdio(false);
	cin >> N >> M;
	set<pair<int, int> > s;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		s.insert(make_pair(a, b));
	}
	bool ret = false;
	for (int i = 2; i <= N - 1; i++) {
		if (s.count(make_pair(1, i)) && s.count(make_pair(i, N))) {
			ret = true;
		}
	}
	cout << (ret ? "POSSIBLE" : "IMPOSSIBLE") << endl;
	return 0;
}