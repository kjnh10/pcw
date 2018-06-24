#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <functional>
#include <ctime>
using namespace std;
#pragma warning(disable: 4996)
string S;
int main() {
	cin >> S;
	for (int i = 0; i < 8; i++) {
		int C = (S[0] - '0');
		for (int j = 0; j < 3; j++) {
			if ((i / (1 << j)) % 2 == 0)C -= (S[j + 1] - '0');
			else C += (S[j + 1] - '0');
		}
		if (C == 7) {
			for (int j = 0; j < 3; j++) {
				cout << S[j];
				if ((i / (1 << j)) % 2 == 0)cout << "-";
				else cout << "+";
			}
			cout << S[3]; cout << "=7" << endl; break;
		}
	}
	return 0;
}