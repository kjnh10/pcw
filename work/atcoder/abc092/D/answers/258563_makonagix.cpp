#include<iostream>
#include<math.h>
#include<string>
#include<algorithm>
using namespace std;

#define rep0(n) for(int i=0;i<n;i++)
#define rep(n) for(int i=1;i<=n;i++)

double const pi = 3.1415926535;
int const mod = 1000000007;
int const inf = 2147483647;

int yesno(bool flag, string yes, string no) {
	if (flag)cout << yes << endl;
	else cout << no << endl;
	return 0;
}

int printint(int n) {
	cout << n << endl;
	return 0;
}

int prints(string s) {
	cout << s << endl;
	return 0;
}

char map[110][110];

int main() {

	for (int i = 1; i <= 100; i++) {
		for (int j = 1; j <= 100; j++) {
			if (i <= 50)map[i][j] = '#';
			else map[i][j] = '.';
		}
	}

	int a, b;
	cin >> a >> b;
	cout << "100 100" << endl;

	a--;
	b--;

	int i = 2;
	while (a >= 1) {
		for (int j = 2; j <= 98; j += 2) {
			if (a == 0)break;
			else {
				map[i][j] = '.';
				a--;
			}
		}
		i += 2;
	}

	i = 52;
	while (b >= 1) {
		for (int j = 2; j <= 98; j += 2) {
			if (b == 0)break;
			else {
				map[i][j] = '#';
				b--;
			}
		}
		i += 2;
	}

	for (int i = 1; i <= 100; i++) {
		for (int j = 1; j <= 100; j++) {
			cout << map[i][j];
		}
		cout << endl;
	}
	return 0;
}