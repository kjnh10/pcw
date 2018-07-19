#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, a; vector<int>p;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a; p.push_back(a);
	}
	sort(p.begin(), p.end());
	p.erase(unique(p.begin(), p.end()), p.end());
	cout << p.size() << endl;
	return 0;
}