#include <iostream>
#include <string>
using namespace std;
int main()
{
	string str, chr;
	int length=1;
	cin >> str;
 
	char c = str[0];
	if (str.size() == 1) {
		cout << c << "1" << endl;
	}else {
		for (int i = 1; i < str.size(); ++i) {
			if (c != str[i]) {
				cout << c << length;
				length = 1;
				c = str[i];
			}
			else {
				length++;
			}
		}
	}
	cout << c << length << endl;
 
 
	return 0;
}