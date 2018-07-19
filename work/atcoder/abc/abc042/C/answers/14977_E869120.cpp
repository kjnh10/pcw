#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
char D[10]; int n, k;
int main() {
	cin >> n >> k;
	for (int i = 0; i < k; i++) { char F; cin >> F; D[F - '0'] = 1; }
	for (int i = n; i < 100000; i++) {
		string S = to_string(i);
		for (int j = 0; j < S.size(); j++) {
			if (D[(S[j] - '0')] == 1)goto E;
		}
		cout << i << endl; break; E:;
	}
	return 0;
}