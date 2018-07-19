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

int a[114514];
int value;

int main() {

	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	a[0] = 0;
	a[n + 1] = 0;
	for (int i = 1; i <= n + 1; i++) {
		value += abs(a[i] - a[i - 1]);
	}
	for (int i = 1; i <= n; i++) {
		cout << value - abs(a[i] - a[i - 1]) - abs(a[i + 1] - a[i]) + abs(a[i + 1] - a[i - 1]) << endl;
	}

	return 0;
}