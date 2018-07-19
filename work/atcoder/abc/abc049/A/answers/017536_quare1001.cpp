#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <iostream>
#include <algorithm>
using namespace std;
string s;
int main() {
	cin >> s;
	char c = s[0];
	if (c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o') cout << "vowel" << endl;
	else cout << "consonant" << endl;
	return 0;
}