#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str;
	string oku = "oku";
	
	cin >> str;

	for (int i = 0; i < str.length(); i++) {
		if (((int)oku.find(str[i]) == -1) && !(str[i] == 'c' && str[i + 1] == 'h') && !(str[i - 1] == 'c' && str[i] == 'h')) {
			cout << "NO" << endl;
			return (0);
		}
	}
	cout << "YES" << endl;

	return (0);
}