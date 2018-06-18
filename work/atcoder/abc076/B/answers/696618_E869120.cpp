#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int N, K, s = 1;
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		s = min(s * 2, s + K);
	}
	cout << s << endl;
	return 0;
}