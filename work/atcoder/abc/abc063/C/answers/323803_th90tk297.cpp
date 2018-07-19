#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	int n; cin >> n;
	vector<int>l;
	int sum = 0;
	for (int i = 0; i < n; i++){
		int s; cin >> s;
		l.push_back(s);
		sum += s;
	}
	if (sum % 10 == 0) {
		sort(l.begin(), l.end());
		for (int i = 0; i < n; i++){
			if (l[i] % 10 != 0) {
				cout << sum - l[i] << endl;
				return 0;
			}
		}
		cout << 0 << endl;
	}
	else cout << sum << endl;
}