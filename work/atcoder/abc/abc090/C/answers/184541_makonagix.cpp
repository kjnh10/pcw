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

	long long a, b;
	cin >> a >> b;
	if (a < b)swap(a, b);
	if (b >= 2) {
		cout << (a - 2)*(b - 2) << endl;
		return 0;
	}
	else if (a >= 2 && b <= 1) {
		cout << a - 2 << endl;
		return 0;
	}
	else cout << 1 << endl;
	
	return 0;
}