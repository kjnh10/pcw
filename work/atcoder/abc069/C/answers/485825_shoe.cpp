#include <bits/stdc++.h>

using namespace std;

int main() {
	int N;
	cin >> N;
	int z = 0, o =  0, t = 0;
	int cur;
	for (int i = 0; i < N; i++) {
		cin >> cur;
		if (cur % 4 == 0) t++;
		else if (cur %2 == 0) o++;
		else z++;
	}
	if (z == t+1 && o ==0) {
		cout << "Yes" << endl;
	}
	else if (z > t) {
		cout << "No" << endl;
	}
	else cout << "Yes" << endl;
	// cin >> N;
}