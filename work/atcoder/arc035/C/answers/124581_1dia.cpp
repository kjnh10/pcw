#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>

#define REP(i,n) for(int i=0;i<n;i++)
#define maxi(a,b) (((a) > (b)) ? (a) : (b))
#define mini(a,b) (((a) < (b)) ? (a) : (b))

using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	/********************************************************/
	string str;
	cin >> str;

	string a, b;
	
	if (str.length() % 2 == 1) {
		a = str.substr(0, str.length() / 2);
		b = str.substr(str.length() / 2 + 1, str.length());
	}
	else {
		a = str.substr(0, str.length() / 2);
		b = str.substr(str.length() / 2, str.length());
	}
	int	j = b.length() - 1;

	string as;
	string bs;
	for (int i = 0; i < str.length() / 2; i++) {
		as = a[i];
		bs = b[j];

		if (as != bs) {
			if (as != "*" && bs != "*") {
				cout << "NO" << endl;
				return 0;
			}
		}
		j -= 1;
	}
		
	cout << "YES" << endl;
	/********************************************************/
	int ret_ = 0;
	return 0;
}