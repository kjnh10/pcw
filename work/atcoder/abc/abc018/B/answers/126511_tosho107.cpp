#include <iostream>
#include <string>

using namespace std;

int main()
{
	const int N = 100;
	int n;
	int l[N], r[N];
	string s;

	cin >> s;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> l[i] >> r[i];
	}
	for (int i = 0; i < n; i++) {
		string t;
		t = s;
		// l[i]文字目からr[i]文字目までの部分を反転させる
		for (int j = l[i] - 1; j < r[i]; j++) {
			s[j] = t[(r[i] - 1) - (j - (l[i] - 1))];
		}
	}
	cout << s << endl;

	return (0);
}
