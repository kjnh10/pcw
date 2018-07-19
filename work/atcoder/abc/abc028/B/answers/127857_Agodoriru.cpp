#include <iostream>
#include <string>

using namespace std;

int main() {
	int a = 0, b = 0, c = 0, d = 0, e = 0, f = 0;
	string s;
	cin >> s;

	for (int i = 0; i<s.size(); i++) {
		if (s[i] == 'A') {
			a++;
		}
		else if (s[i] == 'B') {
			b++;
		}
		else if (s[i] == 'C') {
			c++;
		}
		else if (s[i] == 'D') {
			d++;
		}
		else if (s[i] == 'E') {
			e++;
		}
		else if (s[i] == 'F') {
			f++;
		}
	}

	cout << a << " " << b << " " << c << " " << d << " " << e << " " << f << endl;

	return 0;

}