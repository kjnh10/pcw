#include"bits/stdc++.h"

using namespace std;

int n;
int y;


int main() {
	cin >> n >> y;
	y /= 1000;
	int a = 10;
	int b = 5;
	int c = 1;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			int sum = i + j;
			int rest = n - sum;
			if (rest >= 0) {
				int ans = i*a + b*j + c*rest;
				if (ans == y) {
					cout << i << " " << j << " " << rest << endl;
					return 0;
				}
			}
		}
	}
	puts("-1 -1 -1");
	return 0;
}