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

int yesno(bool f, string yes, string no) {
	if (f)cout << yes << endl;
	else cout << no << endl;
	return 0;
}

int main() {

	string a, b, c;
	cin >> a >> b >> c;
	cout << a[0] << b[1] << c[2] << endl;

	return 0;
}